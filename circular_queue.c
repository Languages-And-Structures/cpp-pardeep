#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;
}q1;

int isFull(q1 *q){
    return (q->r + 1) % q->size == q->f;
}

int isEmpty(q1 *q){
    return q->r==-1;
}

void enqueue(q1 *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Enqueue term :- %d\n",val);
    }
}

int dequeue(q1 *q){
    int val=-1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
        printf("\tDequeue term :- %d\n",val);
        return val;
        
    }
}

int main(){
    q1 *q=(q1*)malloc(sizeof(q1));
    q->size=6;
    q->f=0;
    q->r=0;
    q->arr=(int*)malloc(q->size * sizeof(int));

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,6);
    enqueue(q,6);
    enqueue(q,6);
    enqueue(q,6);
    enqueue(q,6);
    
    free(q->arr);
    free(q);

return 0;
}