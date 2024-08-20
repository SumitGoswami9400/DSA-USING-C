/*Write a c program to create a single list by inserting node at the right hand side
using (malloc)*/


#include<stdio.h>
#include<stdlib.h>

typedef struct slist{
    int data;
    struct slist *next;
}sl;

int main(){
    sl *l=NULL ,*r=NULL, *p=NULL;

    int x,ch,c=0;

    while(1){
        p=(sl*) malloc(sizeof(sl));

        if(p!=NULL){
            printf("Enter value: ");
            scanf("%d",&x);
            p->data=x;

            p->next=l;
            l=p;
         printf("Enter your choice: ");
         scanf("%d",&ch);
         if(ch==0){
            break;
         }
        }
    }
    r->next=NULL;
    p=l;

    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
    p=l;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    printf("Count is %d\n",c);
    return 0;
}
