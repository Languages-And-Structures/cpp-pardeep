#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int r;
    int f;
    int *arr;
} q1;

int isFull(q1 *q)
{
    return (q->r == q->size - 1);
}

int isEmpty(q1 *q)
{
    return (q->r == q->f);
}

void enqueue(q1 *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(q1 *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        int val = -1;
        q->f++;
        val = q->arr[q->f];
        return val;
    }
}

int main()
{
    q1 *q = (q1 *)malloc(sizeof(q1));
    q->size = 200;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS Implementation

    int u;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    /*

         [the tree im using]


             [0]-------[1]
             |          |
             |          |
             |          |
             [2]-------[3]
               \       /
                \     /
                  [4]
                  / \
                 /   \
                [5]  [6]

    */
    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i); // enqueue i for exploration
    while (!isEmpty(q))
    {
        int u = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[u][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}