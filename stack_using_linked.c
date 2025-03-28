#include <stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack * Next;
}s1;

int isEmpty(s1 *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void traversal(s1*top){
    while (top!=NULL)
    {
        printf("Element is %d\n",top->data);
        top=top->Next;
    }
}

int isFull(s1 *top){
    s1 *n=(s1 *)malloc(sizeof(s1));
    if (n==NULL)
    {
        return 1;
    }
    return 0;
    
}

int pop(s1 **top){
    if (isEmpty(*top))
    {
        printf("Stack underflow");
    }
    else{
        s1 *n=(*top);
        *top=(*top)->Next;
        int x=n->data;
        free(n);
        return x;
    }
}

s1 * push(s1 *top,int x){
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else{
        s1 *n=(s1*)malloc(sizeof(s1));
        n->data=x;
        n->Next=top;
        top=n;
    }
}

int peek(s1 *top,int pos){
    s1 *n=top;
    for (int i = 0; (i < pos-1 && n!=NULL); i++)
    {
        n=n->Next;
    }
    if(n!=NULL){
    return n->data;
    }
    else{
        return -1;
    }
}

int stacktop(s1 *top){
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; 
    }
    return top->data;
}

int stackbottom(s1 * top)
{
    while (top->Next!=NULL)
    {
        top=top->Next;
    }
    return top->data;
}

int main(){
    s1 *top=NULL;
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    top=push(top,5);
    // int e=pop(&top);
    // printf("%d\n ",e);
    for (int i = 1; i <= 5; i++)
    {
        printf("Element at %d is: %d\n",i,peek(top,i));
    }
    printf("top:%d\n",stacktop(top));
    printf("bottom:%d\n",stackbottom(top));
    // printf("Peek: %d\n",peek(top,2));
    // traversal(top);
return 0;
}