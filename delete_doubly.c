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

link *deleteatsart(link *head){
    link *ptr=(link*)malloc(sizeof(link));
    ptr->Next=head->Next;
    ptr->Prev=NULL;
    ptr=head;
    free(head);
    return ptr->Next;
}


link* deteteatindex(link* head, int index) {
    if (head == NULL || index < 1) {
        printf("Invalid index\n");
        return head;
    }
    if (index == 1) {
        link* temp = head;
        head = head->Next;
        if (head != NULL) {
            head->Prev = NULL;
        }
        free(temp);
        return head;
    }
    link* ptr = head;
    int i = 1;
    while (ptr != NULL && i < index) {
        ptr = ptr->Next;
        i++;
    }
    if (ptr == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    if (ptr->Prev != NULL) {
        ptr->Prev->Next = ptr->Next;
    }
    if (ptr->Next != NULL) {
        ptr->Next->Prev = ptr->Prev;
    }
    free(ptr);
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
    head=deteteatindex(head,1);
    traversal(head);

return 0;
}