#include<iostream>
#include<bits/stdc++.h>


using namespace std;

// getting longest sum and not adjecent number 


int a=0;
int logestSum(int *arr,int N, int i, int *sum){
    
    if(i >= N){
       return 0;
    }
    if(sum[i] != -1){
     return sum[i];
    }
     int ans1 = logestSum(arr,N, i+1, sum);
     int ans2 = logestSum(arr,N, i+2 , sum) + arr[i];
     a++;
     sum[i] = (ans1 > ans2)? ans1 : ans2;
     return sum[i];
}


int main(){
   
   int *arr,*sum,N;
   cout << "Enter the array size : ";
   cin >> N;
   arr = new int[N];
   sum = new int[N+2];
   cout << "Enter the data to array " << endl;
   for(int i =0;i < N;i++){
      cin >> arr[i];
      sum[i] = -1;
   } 
   sum[N] = -1;
   sum[N + 1] = -1;
   cout << "The Lot House problem answer for given array is : " << logestSum(arr,N,0,sum) << endl;
   delete [] arr;
   delete [] sum;
   cout << " And the number of times reaches : " << a-1 << endl;
   return 0; 
}
