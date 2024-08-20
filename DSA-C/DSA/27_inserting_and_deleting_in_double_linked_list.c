/* Inserting nodes at right hand side in double linked list and delete any node as well as.*/
// call by value


#include<stdio.h>
#include<stdlib.h>


struct dlist{
    int data;
    struct dlist *prev;
    struct dlist *next;
};
struct dlist* Insert(struct dlist*);
void disp(struct dlist*);
struct dlist* Delete(struct dlist*);

int main(){
    struct dlist *l = NULL;
    struct dlist *r = NULL;
    int ch;

    while(1){
        printf("\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        printf("Enter your choice  ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            r = Insert(r);
            if(l == NULL){
                l = r;
            }
            break;

            case 2:
            l = Delete(l);
            if(l == NULL){
                r = l;
            }
            break;

            case 3:
            disp(l);
            break;

            case 4:
            exit(0);
        }
    }
    
    return 0;
}

struct dlist* Insert(struct dlist *r){
    struct dlist *p = NULL;
    int x;
    p = (struct dlist*) malloc(sizeof(struct dlist));

    if(p != NULL){
        printf("Enter node data in Linked list : ");
        scanf("%d",&x);
        p->data  = x;
    }
    
    if(r == NULL){
        r = p;
        p->prev = NULL;
    }
    else{
        r->next = p;
        p->prev = r;
        r = p;
    }
    r->next = NULL;

    return (r);
}

void disp(struct dlist *l){
    if(l == NULL){
        printf("Linked list is empty: ");
    }
    else{
        while(l != NULL){
            printf("%d  ",l->data);
            l = l->next;
        }
    }
}

struct dlist* Delete(struct dlist *l){
    struct dlist *p = NULL;       // l = 2e
    int ch;
    printf("Enter your choice  ");
    scanf("%d",&ch);
    if(l->prev == NULL && l->next == NULL && l->data == ch){ // for remaining element(bas last node ke liye chalega jo bach jayega)
        p = l;
        l = l->next;
        free(p);
        return (l);
    }
    if(l->data == ch){
        p = l;
        l = l->next;
        l->prev = NULL;
    }
    else{
        p = l->next;
        while(p->data != ch && p->next != NULL){
            p = p->next;
        }
        if(p->next != NULL){
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        else if(p->next == NULL && p->data == ch){
            p->prev->next = NULL;
        }
        else{
            printf("Record not found: ");
        }
    }
    free(p);
    return (l);
}