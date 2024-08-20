// Implementatio of Binary tree.


#include<stdio.h>
#include<stdlib.h>
typedef struct Binarytree{
    struct Binarytree *left;
    int data;
    struct Binarytree *right;
}bt;

bt *buildBTree(bt*);
void preorder(bt*);
void inorder(bt*);
void postorder(bt*);

int main(){
    bt *root = NULL;

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = buildBTree(root);
    printf("\nPreorder of this Binary tree:  ");
    preorder(root);
    printf("\nInorder of this Binary tree:  ");
    inorder(root);
    printf("\nPostorder of this Binary tree:  ");
    postorder(root);
    return 0;
}

bt* buildBTree(bt *rt){
    bt *p= NULL;
    int x;

    p = (bt*) malloc(sizeof(bt));

    if(p != NULL){
        printf("Enter the data  ");
        scanf("%d",&x);
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        rt  = p;
        if(x == -1){
            return NULL;
        }

    printf("Enter data for inserting in left of %d\n",x);
    rt->left = buildBTree(rt->left);
    printf("Enter data for inserting in right of %d\n",x);
    rt->right = buildBTree(rt->right);
    }
    return (rt);
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

