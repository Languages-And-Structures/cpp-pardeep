#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} n1;

void enqueue(n1 **f, n1 **r, int val){
    n1 *n = (n1*)malloc(sizeof(n1));
    if (n == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    n->data = val;
    n->next = NULL;
    if (*f == NULL) {
        *f = *r = n;
    } else {
        (*r)->next = n;
        *r = n;
    }
    printf("Enqueued: %d\n", val);
}

int dequeue(n1 **f, n1 **r){
    if (*f == NULL) {
        printf("Queue underflow.\n");
        return -1;
    }
    int val = (*f)->data;
    n1 *temp = *f;
    *f = (*f)->next;
    if (*f == NULL) {
        *r = NULL;
    }
    free(temp);
    printf("Dequeued: %d\n", val);
    return val;
}

void display(n1 *f){
    if (f == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    while (f != NULL) {
        printf("%d -> ", f->data);
        f = f->next;
    }
    printf("NULL\n");
}

int main(){
    n1 *front = NULL;
    n1 *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(front);

    dequeue(&front, &rear);
    display(front);

    dequeue(&front, &rear);
    display(front);

    dequeue(&front, &rear);
    display(front);

    dequeue(&front, &rear);

    return 0;
}