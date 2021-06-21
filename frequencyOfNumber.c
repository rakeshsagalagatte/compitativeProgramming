#include<stdio.h>
#include<stdlib.h>



int frenquency(int *arr, int N){
    int i=0,runlength,runvalue=0,modefrequency=0,mode=0;
    while(i < N){
     runlength = 1;
     runvalue = arr[i];
     while(i + runlength < N && arr[i + runlength] == runvalue){
       runlength += 1;
       mode += 1;
     }
     if(runlength > modefrequency){
        modefrequency = runlength;
     }
     i += runlength;
    }
    return modefrequency;
}


int main(){
 int N;
 printf("Enter the size of array : ");
 scanf("%d",&N);
 int *arr = (int *)malloc(N * sizeof(int));
 int i=0;
 for(i=0;i<N;i++){
   scanf("%d",&arr[i]);
 }
 int max = frenquency(arr,N);
 printf("\nThe Maximum number of times repeation of the number : %d\n", max); 
 return 0;
}
