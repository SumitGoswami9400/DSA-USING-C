// Implementation of Binary Tree using call by reference.


#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryTree{
    struct BinaryTree *left;
    int data;
    struct BinaryTree *right;
}bt;

void buildBTree(bt **);
void preorder(bt*);
void inorder(bt*);
void postorder(bt*);

int main(){
    bt *root = NULL;
    int ch;
    while(1){
    printf("\n1.BuildTree\n2.preorder\n3.inorder\n4-postorder\n5-exit");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        buildBTree(&root);
        break;

        case 2:
        preorder(root);
        break;

        case 3:
        inorder(root);
        break;

        case 4:
        postorder(root);
        break;

        case 5:
        exit(0);
    }
    }
    return 0;
}

void buildBTree(bt **rt){
    bt *p = NULL;
    int x;
    p = (bt*) malloc(sizeof(bt));

    if(p != NULL){
        printf("Enter data: ");
        scanf("%d",&x);

        p->data = x;
        p->left = NULL;
        p->right = NULL;
        *rt = p;
        if(x == -1){
            *rt = NULL;
            return;
        }

    printf("Enter data for inserting in left of %d\n",x);
    buildBTree(&(*rt)->left);
    printf("Enter data for inserting in right of %d\n",x);
    buildBTree(&(*rt)->right);
    }
}

void preorder(bt *rt){
    if(rt != NULL){
        printf("%d ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}
void inorder(bt *rt){
    if(rt != NULL){
        inorder(rt->left);
        printf("%d ",rt->data);
        inorder(rt->right);
    }
}
void postorder(bt *rt){
    if(rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ",rt->data);
    }
}