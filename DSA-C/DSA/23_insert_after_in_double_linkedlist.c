// insert node after a first node in double linked list


#include<stdio.h>
#include<stdlib.h>
struct dlinkedlist{
    int data;
    struct dlinkedlist *prev;
    struct dlinkedlist *next;

};
void linkedlistTravarsal(struct dlinkedlist *ptr){
    while(ptr != NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }
}

void insert(struct dlinkedlist *ptr){
    struct dlinkedlist *p;
    int x;
    p = (struct dlinkedlist*) malloc(sizeof(struct dlinkedlist));
    printf("\nInsert data in node: ");
    scanf("%d",&x);
    p->data = x;
    if(ptr->next == NULL && ptr->prev == NULL){
    ptr->next = p;
    p->prev = ptr;
    p->next = NULL;
    }
   else{ /*if user want to insert more then one node in this double linked 
   list at after first node then else part is execut otherwise no work*/
    p->next = ptr->next;
    ptr->next->prev = p;
    ptr->next = p;
    p->prev = ptr;
   }

}

int main(){
    struct dlinkedlist *p,*q,*r,*s;
    int ch;
    p = (struct dlinkedlist*) malloc(sizeof(struct dlinkedlist));
    q = (struct dlinkedlist*) malloc(sizeof(struct dlinkedlist));
    r = (struct dlinkedlist*) malloc(sizeof(struct dlinkedlist));
    s = (struct dlinkedlist*) malloc(sizeof(struct dlinkedlist));

    p->prev = NULL;
    p->data = 10;
    p->next = NULL;

    while(1){
        printf("\n1-insert\n2-disp\n3-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert(p);
            break;
            case 2:
            linkedlistTravarsal(p);
            break;
            case 3:
            exit(0);
        }
    }

    return 0;
}