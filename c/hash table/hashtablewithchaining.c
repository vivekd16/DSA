#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef struct node{
    int key;
    int value;
    struct node* next;
}n;

n* hashtable[MAX];

int hashfunction(int key){
    return key % MAX;
}

n* createnode(int key,int value){
    n* newnode=(n*)malloc(sizeof(n));
    newnode->key=key;
    newnode->value=value;
    newnode->next=NULL;
    return newnode;
}

void insert(int key, int value){
    int index=hashfunction(key);
    n* newnode=createnode(key,value);
    if(hashtable[index]==NULL){
        hashtable[index]=newnode;
    }else{
        n* temp=hashtable[index];
        while(temp->next!= NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("inserted(%d,%d) at index %d\n",key,value,index);
}
int search(int key){
    int index=hashfunction(key);
    n* temp=hashtable[index];
    while(temp!=NULL){
        if(temp->key==key){
            return temp->value;
        }
        temp=temp->next;
    }
    return -1;
}

void delete(int key){
    int index=hashfunction(key);
    n* temp=hashtable[index];
    n* prev=NULL;

    while(temp!=NULL && temp->key !=key){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("key %d notfound\n",key);
        return;
    }

    if(prev==NULL){
        hashtable[index]=temp->next;
    }else{
        prev->next=temp->next;
    }

    free(temp);
    printf("deleted key%d\n",key);
}

void display(){
    for(int i=0;i<MAX;i++){
        printf("index %d:",i);
        n* temp=hashtable[i];
        while (temp!= NULL){
            printf("(%d,%d)->",temp->key,temp->value);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    for(int i=0;i<MAX;i++){
        hashtable[i]=NULL;
    }

    insert(1, 10);
    insert(2, 20);
    insert(11, 30);
    insert(12, 40);

    display();
    int value=search(11);
    if(value!=-1){
        printf("key 11 found with value%d\n",value);
    }else{
        printf("key 11 not found\n");
    }

    delete(2);
    display();
    return 0;
}