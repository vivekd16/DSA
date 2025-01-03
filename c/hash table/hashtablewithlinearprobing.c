#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashtable[TABLE_SIZE];

int hashfunction(int key){
    return key%TABLE_SIZE;
}

void insert(int key){
    int index=hashfunction(key);
    int originalindex=index;
    while(hashtable[index]!=EMPTY&& hashtable[index]!=DELETED){
        index =(index+1)%TABLE_SIZE;
        if(index==originalindex){
            printf("hash table is full\n");
            return;
        }
    }
    hashtable[index]=key;
    printf("inserted key %d at index %d\n",key ,index);
}

int search(int key){
    int index=hashfunction(key);
    int originalindex=index;
    while(hashtable[index]!=EMPTY){
        if(hashtable[index]==key){
            return index;
        }
        index =(index+1)%TABLE_SIZE;
        if(index==originalindex) break;
    }
    return-1;
}

void delete(int key){
    int index=search(key);
    if(index!=-1){
        hashtable[index]=DELETED;
        printf("key %d deleted\n",key);
    } else {
        printf("key %d not found\n",key);
    }
}

void display(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashtable[i]==EMPTY){
            printf("index %d:EMPTY\n",i);
        }else if (hashtable[i]==DELETED){
            printf("index %d:DELTED\n",i);
        }else{
            printf("index %d:%d\n",i,hashtable[i]);
        }
    }
}
int main(){
    for (int i =0;i<TABLE_SIZE;i++){
        hashtable[i]=EMPTY;
    }

    insert(1);
    insert(11);
    insert(21);
    insert(22);
    display();

    int index =search(11);
    if(index!= -1){
        printf("key 11found at index %d\n",index);
    }else{
        printf("key 11 not found\n");
    }
    delete(11);
    display();
    return 0;
}