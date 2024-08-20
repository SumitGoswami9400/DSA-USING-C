/* Write a c program to print a given number say from 1 to n using recursion */



#include<stdio.h>
void number(int);
int main(){
    int n = 100;
    number(n);
    return 0;
}


void number(int n){
    if(n == 0){
        return;
    }
    number(n-1);
    printf("%d\n",n);
}