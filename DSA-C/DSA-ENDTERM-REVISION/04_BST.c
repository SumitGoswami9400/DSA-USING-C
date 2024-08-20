#include<stdio.h>
#include<stdlib.h>
typedef struct binarystree{
    struct binarystree *left;
    int data;
    struct binarystree *right;
}bst;

void insert(bst ** , int);
void preorder(bst*);
void countTotalnodes(bst*,int*);

int main(){
    bst *root = NULL;
    int ch,v;
    int *c,val;
    while(1){
        printf("\n1-insert\n2-preorder\n3-inorder\n4-postorder\n5-CountTotalnode\n6-coountleftnode");
        printf("\n7-countrightnode\n8-maximumval\n10-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            printf("Enter data: ");
            scanf("%d",&v);
            insert(&root,v);
            break;

            case 2:
            printf("Preorder of this BST is: ");
            preorder(root);
            break;


            case 5:
            c=0;
            countTotalnodes(root,&c);
            printf("Toltal nodes in this BST is: %d",c);
            break;

            case 10:
            exit(0);
        }
    }
    return 0;
}

void insert(bst ** rt,int v){
    bst * p = NULL;

    if(*rt == NULL){
        p = (bst*) malloc(sizeof(bst));
        p->data = v;
        p->left = NULL;
        p->right = NULL;
        *rt = p;
        return;
    }

    else{
        if((*rt)->data > v){
            insert(&(*rt)->left,v);
        }
        else if((*rt)->data < v){
            insert(&(*rt)->right,v);
        }
        else{
            printf("Duplicate element is not allowed");
            return;
        }
    }
}

void preorder(bst* rt){
    if(rt != NULL){
        printf("%d  ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}



void countTotalnodes(bst *rt, int *c){
    if(rt != NULL){
        if(rt->left != NULL, rt->right == NULL){
             (*c)++;
        }
        countTotalnodes(rt->left,c);
        countTotalnodes(rt->right,c);
    }
}

