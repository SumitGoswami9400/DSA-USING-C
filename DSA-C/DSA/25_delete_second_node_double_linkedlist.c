// delete second node in double linked list



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

void delete(struct dlinkedlist *ptr){
    struct dlinkedlist *p;
    int x;
    p = ptr->next;
    ptr->next = p->next;
    p->next->prev = ptr;
    
    free(p);

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

   printf("\nLinked list before deleting\n");
   linkedlistTravarsal(p);
   delete(p);
   printf("\nLinked list after deleting\n");
   linkedlistTravarsal(p);
    return 0;
}
