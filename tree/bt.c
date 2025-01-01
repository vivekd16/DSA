#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}n;

n* createnode(int data){
    n* newnode=(n*)malloc(sizeof(n));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert(n** root,int data){
    if(*root==NULL){
        *root=createnode(data);
        return;
    }
    if(data<(*root)->data){
        insert(&(*root)->left,data);
    } else {
        insert(&(*root)->right,data);
    }
    printf("%d inserted\n",data);
}

n* minvaluenode(n* node){
    n* current=node;
    while(current&& current->left!=NULL){
        current=current->left;
    }
    return current;
}

void deletenode(n** root,int data){
    if (*root ==NULL) return;

    if(data<(*root)->data){
        deletenode(&(*root)->left,data);
    } else if(data>(*root)->data){
        deletenode(&(*root)->right,data);
    } else{
        if((*root)->left==NULL){
            n* temp=(*root)->right;
            free(*root);
            *root=temp;
        }else if((*root)->right==NULL){
            n* temp=(*root)->left;
            free(*root);
            *root=temp;
        }else{
            n* temp=minvaluenode((*root)->right);
            (*root)->data=temp->data;
            deletenode(&(*root)->right,temp->data);
        }
    }
    printf("%d deleted\n",data);
}

void inorder(n* root){
    if(root !=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(n* root){
    if(root !=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(n* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void levelorder(n* root){
    if(root==NULL)return;
    n* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        n* current=queue[front++];
        printf("%d ",current->data);
        if(current->left!=NULL){
            queue[rear++]=current->left;
        }
        if(current->right!=NULL){
            queue[rear++]=current->right;
        }
    }
}

int main(){
    n* root=NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 13);
    insert(&root, 18);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Level-order traversal: ");
    levelorder(root);
    printf("\n");

    printf("Deleting 5...\n");
    deletenode(&root, 5);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}