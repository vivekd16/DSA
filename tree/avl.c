#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node*left,*right;
    int height;
}n;

int getheight(n* node){
    return node?node->height:-1;
}

int max(int a,int b){
    return (a>b)?a:b;
}

n* createnode(int key){
    n* newnode=(n*)malloc(sizeof(n));
    newnode->key=key;
    newnode->left=newnode->right=NULL;
    newnode->height=0;
    return newnode;
}

void rotateright(n** root){
    n* node=*root;
    n* ptr=node->left;
    n* ptr2=ptr->right;
    ptr->right=node;
    node->left=ptr2;
    node->height=max(getheight(node->left),getheight(node->right))+1;
    ptr->height=max(getheight(ptr->left),getheight(ptr->right))+1;
    *root= ptr;
}

void rotateleft(n** root){
    n* node=*root;
    n* ptr=node->right;
    n* ptr2=ptr->left;
    ptr->left=node;
    node->right=ptr2;
    node->height=max(getheight(node->left),getheight(node->right))+1;
    ptr->height=max(getheight(ptr->left),getheight(ptr->right))+1;
    *root= ptr;
}
int getbalance(n* node){
    return node?getheight(node->left)-getheight(node->right):0;
}

void insert(n**root,int key){
    if(!(*root)){
        *root=createnode(key);
        return;
    }
    if(key<(*root)->key){
        insert(&(*root)->left,key);
    }else if(key>(*root)->key){
        insert(&(*root)->right,key);
    }else{
        return;
    }

    (*root)->height=max(getheight((*root)->left),getheight((*root)->right))+1;
    int balance=getbalance(*root);
    if(balance>1 && key<(*root)->left->key){
        rotateright(root);
    }
    if(balance<-1 && key> (*root)->right->key){
        rotateleft(root);
    }
    if(balance>1 && key> (*root)->left->key){
        rotateleft(&(*root)->left);
        rotateright(root);
    }
    if(balance<-1 && key<(*root)->right->key){
        rotateright(&(*root)->right);
        rotateleft(root);
    }
    
}

void inorder(n*root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(){
    n* root=NULL;
    insert(&root,9);
    insert(&root,15);
    insert(&root,20);
    insert(&root,8);
    insert(&root,7);
    insert(&root,13);
    insert(&root,10);
    printf("inorder:");
    inorder(root);
}
