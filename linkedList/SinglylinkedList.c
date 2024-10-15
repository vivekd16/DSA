#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

void insertatbeginnning(node** head_ref,int new_data){
    node* new_node =(node*)malloc(sizeof(node));
    new_node->data =new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void insertatend(node** head_ref,int new_data){
    node* new_node =(node*)malloc(sizeof(node));
    new_node->data =new_data;
    new_node->next =NULL;

    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    node* last=*head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next= new_node;
}

void deletenode(node** head_ref,int key){
    node* temp= *head_ref;  ///why *head
    node* prev =NULL;
    if (temp != NULL && temp->data == key){
        *head_ref=temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL &&temp->data !=key){
        prev =temp;
        temp=temp->next;
    }

    if(temp ==NULL) return;

    prev->next =temp->next;
    free(temp);
}

int search(node* head,int key){
    node* current =head;
    while(current!= NULL){
        if (current->data==key){
            return 1;
        }
        current =current->next;
    }
    return 0;
}

void printlist(node* node){ //using traverse to print
    while(node!=NULL){
        printf("%d ->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

void reverse(node** head_ref){
    node* prev=NULL;
    node* current= *head_ref;
    node* next= NULL;
    
    while(current !=NULL){
        next=current->next;
        current->next=prev;
        prev =current;
        current=next;
    }
    *head_ref=prev;
}

int detectcycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast =fast->next->next;

        if(slow ==fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    node* head=NULL;
    insertatend(&head,1);
    insertatend(&head,2);
    insertatbeginnning(&head,0);
    insertatend(&head,3);

    printf("linked list:");
    printlist(head);
    
    deletenode(&head,2);
    
    printf("after delete:");
    printlist(head);
    
    printf("Search for 3: %s\n", search(head, 3) ? "Found" : "Not Found");
    
    reverse(&head);
    
    printf("Reversed List:\n");
    printlist(head);

    if (detectcycle(head)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle detected\n");
    }

    return 0;
}