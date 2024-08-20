// Binary search Tower of honoi
#include<stdio.h>
#include<stdlib.h>
void TofH(int,char,char,char);
int main(){
    int n;
    printf("how many disk");
    scanf("%d",&n);

    TofH(n,'A','C','B');
    return 0;
}

void TofH(int n,char A,char C,char B){
    if(n == 1){
        printf("\nMoved Disk 1 from rod %c to rod %c ",A,C);
        return;
    }
    TofH(n-1,A,B,C);
   printf("\nMoved Disk %d from rod %c to rod %c ",n,A,C);
   TofH(n-1,B,C,A);
}