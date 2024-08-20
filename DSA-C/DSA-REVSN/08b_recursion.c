// using recursion find factorial of a number
#include<stdio.h>
#include<stdlib.h>
int factorial(int);
int main(){
    int n;
    printf("Enter no of term\n");
    scanf("%d",&n);

    int a = factorial(n);

    printf("Factorial of %d is  %d",n,a);

    return 0;
}

int factorial(int num){
    if(num == 0|| num == 1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}
