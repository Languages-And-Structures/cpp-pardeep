#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * Next;
    struct Node * Prev;
}link;

link *traveral(link *head) {
    link *ptr = head;
    while (ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->Next;
    }
    return head;
}

link *backtraversal(link *head){
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    link *ptr=head;
    while (ptr->Next!=NULL)
    {
        ptr=ptr->Next;
    }
    do
    {
        printf("The element in reverse is %d\n",ptr->data);
        ptr=ptr->Prev;
    } while (ptr!=NULL);
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

    traveral(head);
    backtraversal(head);



return 0;
}