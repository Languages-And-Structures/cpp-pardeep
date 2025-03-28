#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * Next;
}link;

void traversal(link * ptr){
    while (ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->Next;
    }
}

link * insertatfirst(link *head,int data){
    link *ptr=(link*)malloc(sizeof(link));
    ptr->Next=head;
    ptr->data=data;
    return ptr;
}

link * instertinbetween(link *head,int data,int index){
    link *ptr=(link*)malloc(sizeof(link));
    link *p=head;
    int i =0;
    while (i!=index-1)
    {
       p=p->Next;
       i++;
    }
    ptr->data=data;
    ptr->Next=p->Next;
    p->Next=ptr;
    return head;
    
}
link *insertattheend(link *head,int data){
    link *ptr=(link*)malloc(sizeof(link));
    link*p=head;
    while (p->Next!=NULL)
    {
        p=p->Next;
    }
    ptr->data=data;
    p->Next=ptr;
    ptr->Next=NULL;
    return head;
}

int main(){
    link *head;
    link *second;
    link *third;
    link *forth;

    head=(link*)malloc(sizeof(link));
    second=(link*)malloc(sizeof(link));
    third=(link*)malloc(sizeof(link));
    forth=(link*)malloc(sizeof(link));
    int size,a,b,c,d;
    printf("enter in 1st node:-");
    scanf("%d",&a);
    printf("enter in 2st node:-");
    scanf("%d",&b);
    printf("enter in 3st node:-");
    scanf("%d",&c);
    printf("enter in 4st node:-");
    scanf("%d",&d);
    
    head->data=a;
    head->Next=second;
    second->data=b;
    second->Next=third;
    third->data=c;
    third->Next=forth;
    forth->data=d;
    forth->Next=NULL;
    int index,data;
    printf("Enter the data :-");
    scanf("%d",&data);
    printf("Enter the index:-");
    scanf("%d",&index);
    if (index==0)
    {
        head=insertatfirst(head,data);
    }
    else if (index<3&&index<3)
    {
        head=instertinbetween(head,data,index);
    }
    else if (index==3)
    {
        head=insertattheend(head,data);
    }
    traversal(head);
return 0;
}