// Write a c function to find Smallest value in BST.


#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySTree{
    struct BinarySTree *left;
    int data;
    struct BinarySTree *right;
}BST;


void Insert(BST**,int);
int smallest(BST*);

int main(){
    BST *root = NULL;
    int val,ch,g = 0;
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
            g = smallest(root);
            printf("Smallest value in BST is: %d",g);
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

int smallest(BST *rt){
    //BST *p = rt;
    if(rt->left == NULL){
        return -1;
    }
   while(rt->left != NULL){
    rt = rt->left;
   }
  return rt->data;
   
}