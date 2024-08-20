// print 1 to n and n to 1 using recursion

#include<stdio.h>
#include<stdlib.h>
void printnum(int);
int main(){
    int n;

    printf("Enter how many numbers");
    scanf("%d",&n);

    printnum(n);
    return 0;
}

void printnum(int n){

    if(n == 0){
        return;
    }
    printf("%d\n",n);
     printnum(n-1);
  
}