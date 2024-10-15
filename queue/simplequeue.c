#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct queue{
    int arr[MAX];
    int front,rear;
}queue;

void initqueue(queue* q){
    q->front=-1;
    q->rear =-1;
}

int isfull(queue* q){
    return q->rear == MAX-1;
}
int isempty(queue* q){
    return q->front == -1 || q->front > q->rear;
}

void enqueue(queue* q,int item){
    if (isfull(q)){
        printf("queue overflow\n");
        return;
    }
    if (q->front ==-1){
        q->front =0;
    }
    q->arr[++q->rear]=item;
    printf("%d enqueued to queue\n",item);
}

int dequeue(queue* q){
    if(isempty(q)){
        printf("queue underflow\n");
        return -1;
    }
    int item =q->arr[q->front++];
    return item;
}
int peek(queue* q){
    if(isempty(q)){
        printf("queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main(){
    queue q;
    initqueue(&q);
    enqueue(&q,10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d dequeued from queue\n", dequeue(&q));
    printf("Front element is %d\n", peek(&q));

    return 0;
}