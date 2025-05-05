#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} q1;

void enqueue(q1 **f, q1 **r, int val)
{
    q1 *n = (q1 *)malloc(sizeof(q1));
    if (n == NULL)
    {
        printf("queue is full\n");
    }
    else    
    {
        n->data = val;
        n->next = NULL;
        if ((*f) == NULL)
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            (*r) = n;
        }
    }
}

int isEmpty(q1 *f){
    return f==NULL;
}

int isFull(q1 *r){
    q1 *n = (q1 *)malloc(sizeof(q1));
    return n==NULL;
    free(n);
}

int dequeue(q1 **f, q1 **r)
{
    int val = -1;
    q1 *ptr = (*f);
    if ((*f) == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        (*f) = (*f)->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

void traversal(q1 **f)
{
    q1 *temp = *f;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    q1 *f = NULL;
    q1 *r = NULL;

    enqueue(&f, &r, 1);
    enqueue(&f, &r, 2);
    enqueue(&f, &r, 3);
    enqueue(&f, &r, 4);
    enqueue(&f, &r, 5);
    enqueue(&f, &r, 6);
    enqueue(&f, &r, 7);

    traversal(&f);

    printf("dequeued element is :- %d\n", dequeue(&f, &r));
    printf("dequeued element is :- %d\n", dequeue(&f, &r));
    printf("dequeued element is :- %d\n", dequeue(&f, &r));

    traversal(&f);

    return 0;
}