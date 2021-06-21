#include<bits/stdc++.h>

using namespace std;


int longestIncSub(int *input,int N){
    int *output = new int[N];
    output[0] = 1;
    for(int i=1;i < N;i++){
       output[i] = 1;
       for(int j=i-1; j >=0;j--){
          if(input[i] < input[j]){
	    continue;
	  }
	  int times = output[j] + 1;
	  if(times > output[i]){
	    output[i] = times;
	  }
       } 
    }
    int max= output[0];
    for(int i=1;i< N;i++){
       if(max < output[i]){
         max = output[i];
       }
    }
    delete [] output;
    return max;
}


int main(){

   int N;
   cout << "Enter the size of array : ";
   cin >> N;
   int *arr = new int[N];
   cout << "Enter the data to array : " << endl;
   for (int i=0;i < N;i++){
      cin >> arr[i];
   }

   cout << "The logest increasing subsequence is : " << longestIncSub(arr,N) << endl;
   delete [] arr;
   return 0;
}
