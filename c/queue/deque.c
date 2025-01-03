//it is using doubly linked list 

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* front=NULL;
node* rear=NULL;

node* newnode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

int isempty(){
    return front == NULL;
}

void insertfront(int data){
    node* temp=newnode(data);
    if(isempty()){
        front=rear=temp;
    }else{ 
        temp->next=front;
        front->prev=temp;
        front=temp;
    }
    printf("%d inserted at the front\n",data);
}

void insertrear(int data){
    node* temp=newnode(data);
    if(isempty()){
        front=rear=temp;
    }else{
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    printf("%d inserted at the rear\n",data);
}

int deletefront(){
    if(isempty()){
        printf("deque underflow\n");
        return -1;
    }
    node* temp=front;
    int data = temp->data;
    front=front->next;

    if(front ==NULL){
        rear=NULL;
    }else{
        front->prev=NULL;
    }
    free(temp);
    return data;
}

int deleterear(){
    if(isempty()){
        printf("deque underflow\n");
        return -1;
    }
    node* temp=rear;
    int data =temp->data;
    rear =rear->prev;
    
    if(rear==NULL){
        front=NULL;
    }else{
        rear->next=NULL;
    }
    
    free(temp);
    return data;
}
int getfront(){
    if(isempty()){
        printf("deque is empty\n");
        return -1;
    }
    return front->data;
}

int getrear(){
    if(isempty()){
        printf("deque is empty\n");
        return -1;
    }
    return rear->data;
}

int main() {
    insertfront(10);
    insertrear(20);
    insertfront(5);
    insertrear(25);

    printf("Front element is %d\n", getfront());
    printf("Rear element is %d\n", getrear());
    
    printf("%d deleted from front\n", deletefront());
    printf("%d deleted from rear\n", deleterear());

    printf("Front element is %d\n", getfront());
    printf("Rear element is %d\n", getrear());

    return 0;
}