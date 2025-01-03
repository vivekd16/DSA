#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data ;
    struct node* next;
}node;

void insertatbeginning(node** head_ref,int new_data){
    node* new_node=(node*)malloc(sizeof(node));
    node* last= *head_ref;

    new_node->data=new_data;
    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->next=new_node;
    }
    else{
        while(last->next!= *head_ref){
            last=last->next;
        }

        new_node->next= *head_ref;
        last->next=new_node;
        *head_ref=new_node;
    }
}

void insertatend(node** head_ref,int new_data){
    node* new_node=(node*)malloc(sizeof(node));
    node* last= *head_ref;

    new_node->data=new_data;
    new_node->next=*head_ref;
    
    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->next=*head_ref;
    }else{
        while(last->next !=*head_ref){
            last=last->next;
        }
        last->next=new_node;
    }
}

void deletenode(node** head_ref,int key){
    if(*head_ref==NULL)return;
    node *temp=*head_ref,*prev=NULL;

    if(temp->data==key && temp->next ==*head_ref){
        *head_ref=NULL;
        free(temp);
        return;
    }
    if(temp->data==key){
        while(temp->next!=*head_ref){
            temp=temp->next;
        }
        temp->next=(*head_ref)->next;
        free(*head_ref);
        *head_ref=temp->next;
        return;
    }

    prev = *head_ref;
    temp = temp->next;

    while(temp->next !=*head_ref &&temp->data != key){
        prev=temp;
        temp=temp->next;
    }
    if(temp->data ==key){
        prev->next=temp->next;
        free(temp);
    }
}

void printlist(node* head){  //using traverse to print 
    node* temp=head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
        do{
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp!=head);
    printf("(head)\n");
}

int main() {
    node* head = NULL;

    insertatend(&head, 10);
    insertatbeginning(&head, 5);
    insertatend(&head, 20);
    insertatbeginning(&head, 1);

    printf("Circular Linked List:\n");
    printlist(head);

    deletenode(&head, 5);

    printf("After Deleting 5:\n");
    printlist(head);

    return 0;
}
