 #include<stdio.h>
 #define max 20

int main(){
    int a[max],freq[max],n,i,j,count;
    printf("How many values: ");
    scanf("%d",&n);


    printf("Enter %d elements",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        freq[i]=-1;
    }    

    for(i=0;i<n;i++){
        count = 1;
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                count++;
                freq[j]=0;
            }
        }
        if(freq[i]!=0){
            freq[i]=count;
        }
    }

    for(i=0;i<n;i++){
        if(freq[i]!=0){
            printf("%d Occurs %d times",a[i],freq[i]);
        }
        printf("\n");
    }
    return 0;
}