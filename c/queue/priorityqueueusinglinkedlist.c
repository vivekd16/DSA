#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node* next;
}n;

n* newnode(int data,int priority){
    n* temp=(n*)malloc(sizeof(n));
    temp->data=data;
    temp->priority=priority;
    temp->next=NULL;
    return temp;
}
int isempty(n** head){
    return (*head)==NULL;
}

void insert(n** head,int data,int priority){
    n* temp=newnode(data,priority);

    if(isempty(head)||(*head)->priority>priority){
        temp->next=*head;
        *head=temp;
    }else{
        n* current=*head;
        while (current->next!=NULL && current->next->priority<= priority){
            current= current->next;
        }
        temp->next=current->next;
        current->next=temp;
    }
    printf("%d with priority %d inserted\n",data,priority);
}

void deletehighestpriority(n** head){
    if(isempty(head)){
        printf("priority queue undeflow\n");
        return;
    }
    n* temp=*head;
    *head=(*head)->next;
    printf("%d with priority %d deleted\n",temp->data,temp->priority);
    free(temp);
}

int gethighestpriority(n** head){
    if(isempty(head)){
        printf("priority queue is empty\n");
        return -1;
    }
    return (*head)->data;
}

void display(n* head){
    if(isempty(&head)){
        printf("priority queue is empty\n");
        return;
    }
    printf("priority queue elements:\n");
    while(head!=NULL){
        printf("element:%d,priority:%d\n",head->data,head->priority);
        head=head->next;
    }
}

int main() {
    n* pq = NULL;

    insert(&pq, 10, 2);
    insert(&pq, 20, 1);
    insert(&pq, 30, 3);
    insert(&pq, 40, 0);

    display(pq);
    
    deletehighestpriority(&pq);
    display(pq);

    return 0;
}