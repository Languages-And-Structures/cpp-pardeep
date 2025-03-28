#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * Next;
    struct Node * Prev;
}link;

void traversal(link * ptr){
    while (ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->Next;
    }
}

link *insertatstart(link* head,int data){
    link*ptr=(link*)malloc(sizeof(link));
    ptr->data=data;
    ptr->Next=head;
    ptr->Prev=NULL;
    head=ptr;
    return head;
}

link *insertatindex(link *head,int data,int index){
    link* ptr = (link*)malloc(sizeof(link));
    link *q=head;
    int i=0;
    ptr->data=data;
    while(i!=index-1){
        q=q->Next;
        i++;
    }
    ptr->Next=q->Next;
    ptr->Prev=q->Prev;
    q->Next=ptr;
    return head;
}

link *instertatend(link *head,int data){
    link *ptr=(link*)malloc(sizeof(link));
    link *p=head;
    while (p->Next!=NULL)
    {
        p=p->Next;
    }
    ptr->data=data;
    ptr->Next=p->Next;
    ptr->Prev=p->Prev;
    p->Next=ptr;
    return head;
    
}

int main(){
    link * head;
    link * second;
    link * third;
    link * forth;

    head=(link*)malloc(sizeof(link));
    second=(link*)malloc(sizeof(link));
    third=(link*)malloc(sizeof(link));
    forth=(link*)malloc(sizeof(link));

    head->data=1;
    head->Next=second;
    head->Prev=NULL;
    second->data=2;
    second->Next=third;
    second->Prev=head;
    third->data=3;
    third->Next=forth;
    third->Prev=second;
    forth->data=4;
    forth->Next=NULL;
    forth->Prev=third;

    head=instertatend(head,69);
    traversal(head);


return 0;
}