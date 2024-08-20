// Double linked list


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

int main(){
    struct dlinkedlist *p,*q,*r,*s;
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

    linkedlistTravarsal(p);

    return 0;
}