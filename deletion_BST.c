#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
}p1;

p1 *createnode(int data){
    p1 * n;
    n=(p1*)malloc(sizeof(p1));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}

void inorder(p1* root){
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

p1 *inorderpredecessor(p1 *root){
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

p1* deletion(p1 *root,int val){
    p1 *ipre;
    if (root==NULL)
    {
        return 0;
    }
    if (root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if (val<root->data)
    {
        root->left=deletion(root->left,val);
    }
    else if (val>root->data)
    {
        root->left=deletion(root->right,val);
    }
    else{
        ipre=inorderpredecessor(root);
        root->data=ipre->data;
        root->left=deletion(root->left,ipre->data);

    }
    return root;
}

int main(){
    p1 * root =createnode(4);
    p1 * left =createnode(1);
    p1 * right =createnode(6);
    p1 * left_left =createnode(0);
    p1 * right_left =createnode(2);
    
    root->left=left;
    root->right=right;
    left->left=left_left;
    left->right=right_left;

    inorder(root);
    deletion(root,0);
    printf("\n");
    inorder(root);
    
return 0;
}