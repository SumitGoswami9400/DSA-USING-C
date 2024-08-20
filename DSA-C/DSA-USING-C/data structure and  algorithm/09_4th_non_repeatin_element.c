//Write a c program to store N elements in 1 D array then find and print  4th non- repeating element in the array.
#include<stdio.h>

int main(){
  int a[100],n,i,j,found,fourth,count;
  printf("Enter size of array:\n");
  scanf("%d",&n);

  printf("Enter elements in array:\n");
  for(i=0;i<n;i++){      //                           i,
    scanf("%d",&a[i]);   // a[]={1,8,3,5,1,2,3,9,14,2,13,,6,,7,,9,,2}
  }                      //      0,1,2,3,4,5,6,7,8,,9,10,11,12,13,14
  count=0;               //           
  for(i=0;i<n;i++){    // i=2
    found=0;
    for(j=0;j<n;j++){      // j=0
      if(i!=j && a[i]==a[j]){
        found=1;                   
        break; 
      }
    }     // found =0 
      if(!found){
        count++;         // count = 4
        if (count == 4){
        fourth=a[i];       // 8 , 5 , 14 , 13
        break;
        }
      }
  }
   if(count>=4){
        printf("The fourth non repeating element is %d",fourth);
      }
      else{
     printf("There is no 4th repeating element ");
      }
  return 0;
}
