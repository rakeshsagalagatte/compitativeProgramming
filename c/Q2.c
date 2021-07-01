#include <stdio.h>

int partition(int *arr , int low  , int high){
  int pivot = arr[high];
  int i = low -1,j=0,temp=0 ;
  for(j = low ; j <= high-1;j++){
    if(arr[j] < pivot){
      i++;

      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }

  }

      temp = arr[i+1];
      arr[i+1] = arr[high];
      arr[high] = temp;
      return i+1;
}

void quick(int *arr , int low , int high){
 if(low < high){
   int par = partition(arr , low , high);
   quick(arr , low , par- 1);
   quick(arr , par+1 , high);
 }
}

int main(){
 int arra[] = {10 , 2, 5 ,2 , 5, 6 ,8};
 quick(arra , 0 , 6);
 int i=0;
 for(i = 0 ; i < 7 ;i++){
   printf("%d\t", arra[i]);
 }
 return 0;
}
