#include<stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct stack{
    int arr[MAX];
    int top;
}stack;

void initstack(stack* stack){
    stack->top=-1;
}

int isfull(stack* stack){
    return stack->top == MAX - 1;
}

int isempty(stack* stack){
    return stack->top == -1;
}

void push(stack* stack,int item){
    if (isfull(stack)){
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++(stack->top)]=item;
    printf("%d pushed to stack\n",item);
}

int pop(stack* stack){
    if(isempty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peek(stack* stack){
    if (isempty(stack)){
        printf("stack is empty\n");
        return-1;
    }
    return stack->arr[stack->top];
}

int main(){
    stack stack;
    initstack(&stack);
    push(&stack,10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(&stack));

    return 0;
}