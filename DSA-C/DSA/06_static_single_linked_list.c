// static single linked list.
#include<stdio.h>
typedef struct list{
    int data;
    struct list *next;
}l;

int main(){
   l A,B,C, *p=NULL;
   A.data =10;
   B.data =20;
   C.data =30;

   A.next = &B;
   B.next = &C;
   C.next = NULL;

   p=&A;

   while(p!=NULL){
    printf("\n%d",p->data);
    p=p->next;
   }
    return 0;
}