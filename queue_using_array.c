#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;
}q1;

int isFull(q1 *q){
    return q->r==q->size-1;
}

int isEmpty(q1 *q){
    return q->r==q->f;
}

void enqueue(q1 *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(q1 *q){
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else{
        q->f++;
        int val=-1;
        val=q->arr[q->f];
        return val;
    }
}

int main(){
    q1 *q=(q1*)malloc(sizeof(q1));
    q->size=80;
    q->r=q->f=-1;
    q->arr=(int*)malloc(q->size * sizeof(int));

    enqueue(q,12);
    enqueue(q,1);
    enqueue(q,23);
    enqueue(q,90);
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    


    free(q->arr);
    free(q);



return 0;
}