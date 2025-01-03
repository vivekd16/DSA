#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct circularqueue{
    int arr[MAX];
    int front,rear;
}cqueue;

void initqueue(cqueue* q){
    q->front =-1;
    q->rear =-1;
}

int isfull(cqueue* q){
    return(q->rear+1)% MAX == q->front;
}

int isempty(cqueue* q){
    return q->front == -1;
}

void enqueue(cqueue* q,int item){
    if (isfull(q)){
        printf("queue overflow\n");
        return;
    }
    if(q->front ==-1){
        q->front=0;
    }
    q->rear=q->rear+1;
    q->arr[q->rear]=item;
    printf("%d enqueued to queue\n",item);
}

int dequeue(cqueue* q){
    if(isempty(q)){
        printf("queue underflow\n");
        return -1;
    }
    int item=q->arr[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front=(q->front +1);
    }
    return item;
}

int peek(cqueue* q){
    if(isempty(q)){
        printf("queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main(){
    cqueue q;
    initqueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("%d dequeued from queue\n", dequeue(&q));
    enqueue(&q, 60);

    printf("Front element is %d\n", peek(&q));

    return 0;
}