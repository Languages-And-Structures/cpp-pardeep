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

void inorder(p1 *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int isBST(p1 *root)
{
    static p1 *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    p1 *root = createnode(4);
    p1 *left = createnode(1);
    p1 *right = createnode(6);
    p1 *left_left = createnode(0);
    p1 *right_left = createnode(2);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = right_left;
    inorder(root);

    if (isBST(root))
    {
        printf("\nThe tree is an binary search tree\n");
    }
    else
    {
        printf("\nThe tree is not an binary seach tree\n");
    }

    return 0;
}