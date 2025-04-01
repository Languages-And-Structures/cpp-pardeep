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

p1 *search(p1* root,int key)
{
    if (root==NULL)
    {
        return 0;
    }
    if (key==root->data)
    {
        return root;
    }
    else if (root->data<key)
    {
       return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }  
}

p1* searchitr(p1* root,int key){   // without recursion
    while (root!=NULL)
    {
        if (key==root->data)
        {
            return root;
        }
        else if (key > root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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
    printf("\n");
    p1 * n=search(root,6);
    if(n!=NULL){
    printf("Found at :- %d \n",n->data);
    }
    else{
        printf("ELement not found\n");
    }
    return 0;
}