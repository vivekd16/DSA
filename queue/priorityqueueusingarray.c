#include <stdio.h>
#define MAX 100
typedef struct priorityqueue{
    int data;
    int priority;
}pqueue;

pqueue  pq[MAX];
int size=0;

void insert(int data,int priority){
    if(size==MAX){
        printf("priority Queue overflow\n");
        return;
    }
    pq[size].data=data;
    pq[size].priority=priority;
    size++;
    printf("%d with priority %d inserted\n",data,priority);
}

int gethighestpriority(){
    if(size==0){
        printf("priority queue underflow\n");
        return -1;
    }
    int highestpriorityindex=0;
    for(int i=1;i<size;i++){
        if(pq[i].priority<pq[highestpriorityindex].priority){
            highestpriorityindex=i;
        }
    }
    return highestpriorityindex;
}

void deletehighestpriority(){
    if(size==0){
        printf("priority queue underflow\n");
        return;
    }
    int highestpriorityindex=gethighestpriority();
    printf("%d wiht priority %d delete\n",pq[highestpriorityindex].data,pq[highestpriorityindex].priority);

    for(int i=highestpriorityindex;i<size-1;i++){
        pq[i]=pq[i+1];
    }
    size--;
}

void display(){
    if(size==0){
        printf("priority queue is empty\n");
        return;
    }
    printf("priority queue element:\n");
    for(int i=0;i<size;i++){
        printf("element: %d,priority:%d\n",pq[i].data,pq[i].priority);
    }
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    
    display();
    
    deletehighestpriority();
    display();
    
    deletehighestpriority();
    display();
    
    return 0;
}