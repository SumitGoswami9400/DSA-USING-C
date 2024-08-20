/* Write a c program to print a given number say from n to 1 using recursion (premitive) recursion */


#include<stdio.h>
void number(int);
int main(){
    int n = 10;
    number(n);
    return 0;
}
void number(int n){
    if(n == 0){
        return;
    }
    printf("%d\n",n);
    number(n-1);
}