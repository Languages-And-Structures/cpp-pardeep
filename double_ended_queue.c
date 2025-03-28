#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    int size;
    int f;
    int r;
    int *arr;
} q1;

int isFull(q1 *q)
{
    return q->r == q->size - 1;
}

int isEmpty(q1 *q)
{
    return q->r < q->f;
}

void enqueuefromrear(q1 *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

void enqueuefromfront(q1 *q, int val)
{
    if (q->f == 0)
    {
        printf("Cannot enqueue from front. Front is at the boundary.\n");
    }
    else
    {
        if (q->f == -1) 
        {
            q->f = q->r = 0;
        }
        else
        {
            q->f--;
        }
        q->arr[q->f] = val;
    }
}

int dequeuefromfront(q1 *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int val = q->arr[q->f];
        q->f++;
        if (q->f > q->r)
        {
            q->f = q->r = -1; 
        }
        return val;
    }
}

int dequeuefromrear(q1 *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        int val = q->arr[q->r];
        q->r--;
        if (q->f > q->r)
        {
            q->f = q->r = -1; 
        }
        return val;
    }
}

void display(q1 *q)
{
    if (isEmpty(q))
    {
        printf("Nothing to display\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->f; i <= q->r; i++)
        {
            printf("%d -> ", q->arr[i]);
        }
        printf("NULL\n");
    }
}

int main()
{
    q1 *q = (q1 *)malloc(sizeof(q1));
    q->size = 2;
    q->r = q->f = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    char c[20], ch[20];

    while (1)
    {
        printf("\nEnter \n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Where do you want to add from? (front/rear): ");
            scanf("%s", ch);
            int val;
            printf("Enter the Value you want to enter: ");
            scanf("%d", &val);
            if (strcmp(ch, "front") == 0)
            {
                enqueuefromfront(q, val);
            }
            else if (strcmp(ch, "rear") == 0)
            {
                enqueuefromrear(q, val);
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;

        case 2:
            printf("Where do you want to delete from? (front/rear): ");
            scanf("%s", ch);
            if (strcmp(ch, "front") == 0)
            {
                printf("Dequeued Element is: %d\n", dequeuefromfront(q));
            }
            else if (strcmp(ch, "rear") == 0)
            {
                printf("Dequeued Element is: %d\n", dequeuefromrear(q));
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;

        case 3:
            display(q);
            break;

        case 4:
            free(q->arr);
            free(q);
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
} 
