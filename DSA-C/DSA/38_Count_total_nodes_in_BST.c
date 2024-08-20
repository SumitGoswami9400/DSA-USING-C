// Write a c function to count total number of node in a binary search tree.


#include<stdio.h>
#include<stdlib.h>

typedef struct Binarysearchtree{
    struct Binarysearchtree *left;
    int data;
    struct Binarysearchtree *right;
}BST;

void Insert(BST **,int);
void count(BST*,int*);

int main(){
    BST *root = NULL;
    int ch;
    int val;
    int *c = 0;
    while(1){
    printf("\n1.Insert\n2.count\n3.exit");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("Enter data: ");
        scanf("%d",&val);
        Insert(&root,val);
        break;

        case 2:
        count(root,&c);
        printf("Total nodes present in BST is: %d",c);
        break;

        case 3:
        exit(0);
    }
    }
    return 0;
}

void Insert(BST **rt,int v){
    BST *p = NULL;
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

void count(BST *rt,int *c){
    if(rt != NULL){
        (*c)++;
        count(rt->left,c);
        count(rt->right,c);
    }
}
