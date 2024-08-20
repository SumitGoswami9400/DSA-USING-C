// using recursion print finbonacci series
#include<stdio.h>
#include<stdlib.h>
int fibonacciseries(int n);
int main(){
    int n,i;
    printf("Enter no of terms ");
    scanf("%d",&n);

    printf("Fibonacci series for %d term\n",n);

    for(i=0;i<n;i++){
        printf("%d  ",fibonacciseries(i));
    }
    return 0;
}

int fibonacciseries(int num){
    if(num == 0){
        return  0;
    }
    else if(num == 1){
        return 1;
    }
    return fibonacciseries(num-1)+fibonacciseries(num-2);
}

// Fibonacci Series using Recursion
/*#include <stdio.h>
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 
int main()
{
    int n = 9;
    printf("%d", fib(n));
   
    return 0;
}*/