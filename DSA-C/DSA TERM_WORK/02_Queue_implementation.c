/*Write a C program to Insert and Delete elements form a Queue using link list ,each node
should have the following information about a product Product_Id(char) , Product_Name(string) 
,Total_sale(integer),Product_Grade(Char).*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue{
    struct queue *next;
    char PI;
    char PN[100];
    int TS;
    char PG;
};

void enq(struct queue** , struct queue**,char,char *,int,char);
void deq(struct queue** , struct queue**);
void disp(struct queue*);

int main(){
    struct queue *r = NULL , *f=NULL;
   int ch, PI, TS;
  char PN[100], PG;

    while(1){
        printf("\n------MENU------");
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
        printf("Enter product ID: ");
        scanf("%d", &PI);
        printf("Enter product name: ");
        scanf("%s",PN);
        printf("Enter total sale: ");
        scanf("%d", &TS);
        printf("Enter product grade: ");
        scanf(" %c", &PG);
        enq(&f,&r, PI, PN, TS, PG);
            break;
            case 2:
            deq(&f,&r);
            break;
            case 3:
            disp(f);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}

void enq(struct queue **f,struct queue **r,char PI, char *PN, int TS, char PG){
    struct queue *p = NULL;
    int x;
    
    p = (struct queue*) malloc(sizeof(struct queue));

    if(p != NULL){
    
        p->PI = PI;
        strcpy(p->PN, PN);
        p->TS = TS;
        p->PG = PG;
        p->next = NULL;
        if(*f == NULL && *r==NULL){
            *f = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
            (*r)->next = NULL;
        }
    }
}

void deq(struct queue **f,struct queue **r){
    struct queue *p = NULL;

    if(*f == NULL && *r == NULL){
        printf("Queue is empty: ");
    }
    else{
        p = *f;
        printf("Deleted info is :\nProduct ID: %d\nProduct Name: %s\nTotal Sale: %d\nProduct Grade: %c\n", (*f)->PI, (*f)->PN, (*f)->TS, (*f)->PG);
        if(*f == *r){
            *f = *r = NULL;
        }
        else{
            *f = (*f)->next;
        }
        free(p);
    }
}

void disp(struct queue *f){
    if(f == NULL){
        printf("Queue is empty: ");
    }
    else{
        while (f != NULL)
        {
            printf("Product ID: %d\nProduct Name: %s\nTotal Sale: %d\nProduct Grade: %c\n", f->PI, f->PN, f->TS, f->PG);
            f = f->next;
        }
    }
}


