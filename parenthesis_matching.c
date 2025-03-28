#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} s1;

int isEmpty(s1 *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(s1 *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(s1 *s, char x)
{
    if (isFull(s))
    {
        printf("stack overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}
char pop(s1 *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow");
    }
    else
    {
        char x = s->arr[s->top];
        s->top--;
        return x;
    }
}

int parenthesis(s1 *s, char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{'||exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')'||exp[i] == '}'||exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(s);
        }
    }
    return isEmpty(s) ? 1 : 0;
}

int main()
{
    s1 *s = (s1 *)malloc(sizeof(s1));
    s->size = 80;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    printf("Enter ur expression\t:-");
    char *ch = (char *)malloc(s->size * sizeof(char));
    scanf("%[^\n]", ch);

    int x = parenthesis(s, ch);

    if (x == 1)
    {
        printf("Expression is balanced\n");
    }
    else
    {
        printf("Expression is unbalanced\n");
    }
    free(s->arr);
    free(s);
    free(ch);
    return 0;
}