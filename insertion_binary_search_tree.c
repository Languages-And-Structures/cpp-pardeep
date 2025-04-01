#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
}p1;

p1 * createnode(int data){
    p1 *n;
    n=n = (p1 *)malloc(sizeof(p1));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(p1 *root,int key){
    p1 *prev=NULL;
    p1 * ptr;
    while (root!=NULL)
    {
        prev=root;
        if (key==root->data)
        {
            return;
        }
        else if (key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    
    p1 *new=(p1*)malloc(sizeof(p1));
    new=createnode(key);
    if (key<prev->data)
    {
        prev->left=new;
    }
    else{
        prev->right=new;
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

int main(){
    p1 *root = createnode(4);
    p1 *left = createnode(1);
    p1 *right = createnode(6);
    p1 *left_left = createnode(0);
    p1 *right_left = createnode(2);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = right_left;

    insert(root,9);
    inorder(root);

return 0;
}