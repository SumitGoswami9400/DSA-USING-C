// insert new node before the last node


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
    printf("\nInsert node: ");
    scanf("%d",&x);
    p->data = x;

    while(ptr->next->next != NULL){
    ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next->prev = p;
    ptr->next = p;
    p->prev = ptr;
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
    p->next = q;

    q->prev = p;
    q->data = 20;
    q->next = r;

    r->prev = q;
    r->data = 30;
    r->next = s;

    s->prev = r;
    s->data = 40;
    s->next = NULL;

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
