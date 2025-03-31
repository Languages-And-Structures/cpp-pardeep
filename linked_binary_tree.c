#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} p1;

p1 *createnode(int data)
{
    p1 *n;
    n = (p1 *)malloc(sizeof(p1));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(p1 *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(p1 *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(p1 *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main()
{
    p1 *root = createnode(4);
    p1 *left = createnode(1);
    p1 *right = createnode(6);
    p1 *left_left = createnode(5);
    p1 *right_left = createnode(2);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = right_left;
    int s;
    while (1)
    {
        printf("\nWhich type of travesal do you want\n1-Preorder\t2-postprder\t3-inorder\t4-EXIT\n\n");
        printf("ENTER:- ");
        scanf("%d", &s);
        if (s == 1)
        {
            preorder(root);
        }
        else if (s == 2)
        {
            postorder(root);
        }
        else if (s == 3)
        {
            inorder(root);
        }
        else if(s==4){
            break;
        }
    }
    return 0;
}