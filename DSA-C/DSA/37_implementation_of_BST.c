// Implementation of BST.
// Using call by reference


#include<stdio.h>
#include<stdlib.h>


typedef struct Binarysearchtree{
    struct Binarysearchtree *left;
    int data;
    struct Binarysearchtree *right;
}BST;

void Insert(BST **,int);
void preorder(BST*);
void inorder(BST*);
void postorder(BST*);

int main(){
    BST *root = NULL;
    int ch;
    int val;
    while(1){
    printf("\n1.Insert\n2.preorder\n3.inorder\n4-postorder\n5-exit");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("Enter data: ");
        scanf("%d",&val);
        Insert(&root,val);
        break;

        case 2:
        printf("\nPreorder of this Binary tree:  ");
        preorder(root);
        break;

        case 3:
        printf("\ninorder of this Binary tree:  ");
        inorder(root);
        break;

        case 4:
        printf("\nPostorder of this Binary tree:  ");
        postorder(root);
        break;

        case 5:
        exit(0);
    }
    }
    return 0;
}

void Insert(BST **rt,int v){
    BST *p = NULL;
    /*int x;
    printf("Enter data: ");
    scanf("%d",&x);*/
    if(*rt == NULL){
    p = (BST*) malloc(sizeof(BST));
        p->data = v;
        p->left = NULL;
        p->right = NULL;
        *rt = p;
        return;
    }
    else{
        if((*rt)->data > v){
            Insert(&(*rt)->left,v);
        }
        else if((*rt)->data < v){
            Insert(&(*rt)->right,v);
        }
        else{
            printf("Duplicate are not allowed ");
            return;
        }
    }
    
}

void preorder(BST *rt){
    if(rt != NULL){
        printf("%d ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}
void inorder(BST *rt){
    if(rt != NULL){
        inorder(rt->left);
        printf("%d ",rt->data);
        inorder(rt->right);
    }
}
void postorder(BST *rt){
    if(rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ",rt->data);
    }
}