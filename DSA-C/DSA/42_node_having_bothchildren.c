// Write a c function to count node having both children.


#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySTree{
    struct BinarySTree *left;
    int data;
    struct BinarySTree *right;
}BST;

void Insert(BST**,int);
void countbothchild(BST*,int*);

int main(){
    BST *root = NULL;
    int val,ch,*c = 0;
    while(1){
        printf("\n1.Insert\n2.Count\n3.Exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data: ");
            scanf("%d",&val);
            Insert(&root,val);
            break;

            case 2:
            countbothchild(root,&c);
            printf("Total count of nodes Having both child is: %d",c);
            break;

            case 3:
            exit(0);
        }
    }
    return 0;
}

void Insert(BST **rt, int v){
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
            printf("Duplicate elements is not allowed ");
            return;
        }
    }
}

void countbothchild(BST *rt,int *c){
    if(rt != NULL){
        if(rt->left != NULL && rt->right != NULL){
        (*c)++;
        }
        countbothchild(rt->left,c);
        countbothchild(rt->right,c);
    }
}