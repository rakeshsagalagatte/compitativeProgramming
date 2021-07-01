#include<bits/stdc++.h>

using namespace std;

int nextIndex(int *arr, int X, int N, int index){
    int count = 0;
    while(1){
        if(arr[index] != INT_MAX){
            count += 1;
            if(count == X){
                cout << index << endl;
                break;
            }
        }
        index = (index+1)%N;
    }
    return index;
}

int lastIndex(int *arr, int N, int X){
    int n=N,index=0;
    while(n > 1){
       index = nextIndex(arr,X,N,index); 
       arr[index] = INT_MAX;
       n--;
    }
    return nextIndex(arr, X, N, index);
}

int main(){
    int N=5;
    int X=3, arr[] = {1,2,3,4,5};
    // cout << "Enter the size of the array :  " << endl;
    // cin >> N;
    // cout << "Enter array Elements : " << endl;
    // int *arr = new int[N];
    // for(int i =0 ; i < N; i++){
    //     cin >> arr[i];
    // }
    // cout << "Enter the Xth element index : " << endl;
    // cin >> X;
    cout << " Last element index : " << lastIndex(arr, N, X) << endl;
    return 0;
}