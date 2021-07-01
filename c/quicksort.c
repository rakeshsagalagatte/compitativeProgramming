#include<stdio.h>
#include<stdlib.h>


int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int pindex = low;
    for(int i=low; i <= high-1;i++){
       if(arr[i] <= 
    }
}

void quickSort(int *arr,int low, int high){

	if(low < high){
	 int index = partition(arr,low,high);
	 quickSort(arr, low , index-1);
	 quickSort(arr, index+1, high);
	}
}


int main(){

}
