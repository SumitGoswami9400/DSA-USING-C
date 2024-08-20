/*Write C program to create a binary search tree and then write ‘C’ function for following operations
i) Count total no. of nodes
ii) Count total no. of  leaf nodes.
iii) Count total no.  having left child only.
(iv) Count total no. of   nodes having both children.
(v) Display node having max. information.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Binarysearchtree{
    struct Binarysearchtree *left;
    int data;
    struct Binarysearchtree *right;
}BST;

void Insert(BST **,int);
void countTnodes(BST*,int*);
void countTleafnode(BST *,int*);
void countleftchild(BST *,int*);
void countbothchild(BST *,int*);
int maxinfo(BST*);

int main(){
    BST *root = NULL;
    int ch;
    int val;
    int *c,g=0;
    while(1){
    printf("\n1.Insert\n2.countTnodes\n3.Countleafnodes\n4.Havinleftonly\n5.havinbothnode\n6.Maximuminfo\n7.exit");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("Enter data: ");
        scanf("%d",&val);
        Insert(&root,val);
        break;

        case 2:
        c = 0;
        countTnodes(root,&c);
        printf("Total nodes present in BST is: %d",c);
        break;

        case 3:
        c = 0;
        countTleafnode(root,&c);
        printf("Total leaf nodes is: %d",c);
        break;

        case 4:
        c = 0;
        countleftchild(root,&c);
        printf("Total no of left child only is: %d",c);
        break;

        case 5:
        c = 0;
        countbothchild(root,&c);
        printf("Total no of left child only is: %d",c);
        break;

        case 6:
        g = maxinfo(root);
        printf("Maximum value in BST is: %d",g);
        break;

        case 7:
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

void countTnodes(BST *rt,int *c){
    if(rt != NULL){
        (*c)++;
        countTnodes(rt->left,c);
        countTnodes(rt->right,c);
    }
}

void countTleafnode(BST *rt,int *c){
    if(rt != NULL){
        if(rt->left == NULL && rt->right == NULL){
        (*c)++;
        }
        countTleafnode(rt->left,c);
        countTleafnode(rt->right,c);
    }
}

void countleftchild(BST *rt,int *c){
    if(rt != NULL){
        if(rt->left != NULL && rt->right == NULL){
        (*c)++;
        }
        countleftchild(rt->left,c);
        countleftchild(rt->right,c);
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

int maxinfo(BST *rt){
    //BST *p = rt;
    if(rt->right == NULL){
        return -1;
    }
   while(rt->right != NULL){
    rt = rt->right;
   }
  return rt->data;
   
}