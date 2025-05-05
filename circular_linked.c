#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *Next;
} link;

link *traveral(link *head)
{
    link *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->Next;
    } while (ptr != head);
    return head;
}

link *insertatstart(link *head, int data)
{
    link *ptr = (link *)malloc(sizeof(link));
    ptr->data = data;
    link *p = head->Next;
    while (p->Next != head)
    {
        p = p->Next;
    }
    p->Next = ptr;
    ptr->Next = head;
    head = ptr;
    return head;
}
link *insertatstart2(link *head, int data)
{
    link*ptr=(link*)malloc(sizeof(link));
    ptr->data=data;
    link *p=head->Next;
    while (p->Next!=head)
    {
        p=p->Next;
    }
    p->Next = ptr;
    ptr->Next = head;
    head = ptr;
    return head;
}
link *insertinbetween(link* head, int index,int data){
    link *ptr=(link*)malloc(sizeof(link));
    link*p=head;
    int i=0;
    while(i!=index-1){
        p=p->Next;
        i++;
    }
    ptr->data=data;
    ptr->Next=p->Next;
    p->Next=ptr;
    return head;
}
link *insertatend(link* head,int data){
    link *ptr=(link*)malloc(sizeof(link));
    link *p=head->Next;
    while(p->Next!=head){
        p=p->Next;
    }
    ptr->data=data;
    p->Next=ptr;
    ptr->Next=head;
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

    head->data = 1;
    head->Next = second;
    second->data = 2;
    second->Next = third;
    third->data = 3;
    third->Next = forth;
    forth->data = 4;
    forth->Next = head;
    head = insertatstart(head, 69);
    traveral(head);

    return 0;
}