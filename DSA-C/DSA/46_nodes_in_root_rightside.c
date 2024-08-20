// Write a c function to count total number of node in the right hend side in the root node.



#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySTree{
    struct BinarySTree *left;
    int data;
    struct BinarySTree *right;
}BST;

void Insert(BST**,int);
void countRHS(BST*,int*,int);

int main(){
    BST *root = NULL;
    int ch,val;
    int *c = 0,rv;
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
            rv = root->data;
            countRHS(root,&c,rv);
            printf("Total elements in Root right side is: %d",c);
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
            printf("Duplicate element is not allowed ");
            return;
        }
    }
}

void countRHS(BST *rt,int *c,int rv){
    if(rt != NULL){
    if(rt->data > rv){
    (*c)++;
    }
    else if(rt->data < rv){
        return;
    }
    countRHS(rt->left,c,rv);
    countRHS(rt->right,c,rv);
    }
}