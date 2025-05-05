#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
} s1;

int isEmpty(s1 *s)
{
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(s1 *s)
{
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(s1 *s,int val){
    if(isFull(s)){
        printf("stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=val;
    }
} 
int pop(s1 *s){
    if(isEmpty(s)){
        printf("stack underflow\n");
        return -1;
    }
    else{
        int val=s->arr[s->top];
        s->top--; 
        return val;
    }

}
int peek(s1 *s,int i){
    if (s->top-i+1<0)
    {
        printf("invaild\n");
        return -1;
    }
    else{
        return s->arr[s->top-i+1];
    }
}

int stacktop(s1 * s){
    return s->arr[s->top];
}

int stacktop(s1 * s){
    return s->arr[0];
}

int main()
{
    s1 *s = (s1 *)malloc(sizeof(s1));
    s->top = -1;
    s->size = 80;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    printf("After pushing full:%d\n",isFull(s));
    printf("%d\n",peek(s,2));
return 0;
}