//Write a c program to store N elements in 1 D array then find and print  4th  repeating element in the array.
#include<stdio.h>
#include<stdlib.h>
/*int main(){
  int a[100],n,i,j,found,fourth,count;
  printf("Enter size of array:\n");
  scanf("%d",&n);
  printf("Enter elements in array:\n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  count=0;
  for(i=0;i<n;i++){
    //found=0;
    for(j=i+1;j<n;j++){
      if(a[i]==a[j]){
        found=1;
        count++;
      if(count==3){
        fourth=a[i];// record the vlue of third repeating element.
      }
      else if(count==4){
        printf("The fourth repeating element is %d",a[i]);
        return 0; // you found foutrh repeating element exit from your program.
      }
      break;// if you found ones repeat no need to check further.
      }
    }
  }
  printf("There is no 4th repeating element ");
  return 0;
}*/

// using dynamic memory allocation
int main(){
  int *ptr;
  int i,j,n,fourth,found,count;
  printf("Enter how many number you want to insert: \n");
  scanf("%d",&n);

  ptr = (int *) malloc(n * sizeof(int));

  printf("Enter elements: \n");
  for(i=0;i<n;i++){
    scanf("%d",&ptr[i]);
  }

  count=0;
  for(i=0;i<n;i++){
    //found=0;
    for(j=i+1;j<n;j++){
      if(ptr[i]==ptr[j]){
        found=1;
        count++;
      if(count==3){
        fourth=ptr[i];// record the vlue of third repeating element.
      }
      else if(count==4){
        printf("The fourth repeating element is %d",ptr[i]);
        return 0; // you found foutrh repeating element exit from your program.
      }
      break;// if you found ones repeat no need to check further.
      }
    }
  }
  printf("There is no 4th repeating element ");
  return 0;
}

