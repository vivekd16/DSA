#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

void insertatbeginning(node** head_ref,int new_data){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    new_node->prev=NULL;

    if (*head_ref!=NULL){
        (*head_ref)->prev=new_node;
    }
    *head_ref=new_node;
}

void insertatend(node** head_ref,int new_data){
    node* new_node=(node*)malloc(sizeof(node));
    node* last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref==NULL){
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }
    
    while(last->next!= NULL){
        last=last->next;
    }
    last->next=new_node;
    new_node->prev=last;
}

void deletenode(node** head_ref,node* del_node){
    if(*head_ref==NULL || del_node ==NULL) return;
    
    if(*head_ref ==del_node){
        *head_ref= del_node->next;
    }
    
    if(del_node->next !=NULL){
        del_node->next->prev=del_node->prev;
    }

    if(del_node->prev !=NULL){
        del_node->prev->next=del_node->next;
    }
    free(del_node);
}

void printlist(node* Node){ //using traverse to print
    node* last;
    printf("traversal in forward direction:\n");
    while(Node !=NULL){
        printf("%d->",Node->data);
        last=Node;
        Node=Node->next;
    }
    printf("NULL\n");
    printf("traversal in reverse direction:\n");
    while(last!=NULL){
        printf("%d->",last->data);
        last=last->prev;
    }
    printf("NULL\n");
}

void reverse(node** head_ref){
    node* temp=NULL;
    node* current= *head_ref;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if (temp!=NULL){
        *head_ref=temp->prev;
    }
}

int detectcycle(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         
        fast = fast->next->next;   
        if (slow == fast) {
            return 1;   
        }
    }
    return 0;  
}

int main(){
    node* head=NULL;
    insertatend(&head,10);
    insertatbeginning(&head,5);
    insertatend(&head, 15);
    insertatbeginning(&head, 2);
    printf("Doubly Linked List:\n");
    printlist(head);

    deletenode(&head, head->next); 

    printf("\nAfter Deleting node 5:\n");
    printlist(head);

    reverse(&head);
    
    printf("\nReversed List:\n");
    printlist(head);

    if (detectcycle(head)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle detected\n");
    }
    return 0;
}