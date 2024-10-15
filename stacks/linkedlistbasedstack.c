#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* newnode(int data){
    node* Node=(node*)malloc(sizeof(node));
    Node->data=data;
    Node->next=NULL;
    return Node;
}

int isempty(node* head){
    return !head;
}

void push(node** head,int data){
    node* Node=newnode(data);
    Node->next=*head;
    *head=Node;
    printf("%d pushed to stack\n", data);
}

int pop(node** head){
    if(isempty(*head)){
        printf("Stack Underflow\n");
        return -1;
    }
    node* temp=*head;
    *head=(*head)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}

int peek(node* head){
    if(isempty(head)){
        printf("stackis empty\n");
        return -1;
    }
    return head->data;
}

int main(){
    node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    printf("%d popped from stack\n", pop(&head));
    printf("Top element is %d\n", peek(head));

    return 0;
}