#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *Next;
} link;

void traversal(link *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->Next;
    }
}

link *deleteatstart(link *head)
{
    link *ptr = (link *)malloc(sizeof(link));
    ptr->Next = head;
    head = head->Next;
    free(ptr);
    return head;
}

link *deleteinbetween(link *head, int index)
{
    link *ptr = head;
    int i = 0;
    if (head == NULL || index < 0)
    {
        printf("Invalid index\n");
        return head;
    }
    while (i != index - 1)
    {
        ptr = ptr->Next;
        i++;
    }
    link *q = ptr->Next;
    ptr->Next = q->Next;
    free(q);
    return head;
}

link *deleteatend(link *head)
{
    link *ptr = (link *)malloc(sizeof(link));
    if (head == NULL || head->Next == NULL)
    {
        free(head);
        return NULL;
    }
    ptr->Next = head;
    int i = 0;
    while (ptr->Next->Next != NULL)
    {
        ptr = ptr->Next;
    }
    free(ptr->Next);
    ptr->Next = NULL;
    return head;
}

int main()
{
    link *head;
    link *second;
    link *third;
    link *forth;

    head = (link *)malloc(sizeof(link));
    second = (link *)malloc(sizeof(link));
    third = (link *)malloc(sizeof(link));
    forth = (link *)malloc(sizeof(link));
    int index, a, b, c, d;
    printf("enter in 1st node:-");
    scanf("%d", &a);
    printf("enter in 2st node:-");
    scanf("%d", &b);
    printf("enter in 3st node:-");
    scanf("%d", &c);
    printf("enter in 4st node:-");
    scanf("%d", &d);

    head->data = a;
    head->Next = second;
    second->data = b;
    second->Next = third;
    third->data = c;
    third->Next = forth;
    forth->data = d;
    forth->Next = NULL;
    printf("enter in index:-");
    scanf("%d", &index);

    if (index == 0)
    {
        head = deleteatend(head);
    }
    else if (index < 3 && index < 3)
    {
        head = deleteinbetween(head, index);
    }
    else if (index == 3)
    {
        head = deleteatend(head);
    }
    traversal(head);
    return 0;
}