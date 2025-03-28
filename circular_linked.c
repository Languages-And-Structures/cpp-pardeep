#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * Next;
}link;


link *traveral(link *head){
    link *ptr=head;
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->Next;
    } while (ptr!=head);
    return head;
}

link *insertatstart(link *head,int data){
    link *ptr=(link*)malloc(sizeof(link));
    ptr->data=data;
    link *p=head->Next;
    while(p->Next!=head){
        p=p->Next;
    }
    p->Next=ptr;
    ptr->Next=head;
    head=ptr;
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
    second->data=2;
    second->Next=third;
    third->data=3;
    third->Next=forth;
    forth->data=4;
    forth->Next=head;
    head=insertatstart(head,69);
    traveral(head);

    



return 0;
}