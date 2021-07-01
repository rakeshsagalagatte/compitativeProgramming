#include<bits/stdc++.h>

using namespace std;

vector<int> bitPos(long long int num){
   vector<int> bitPosArray;
   long long int b=0;
   if(num ==0 ){
       bitPosArray.push_back(0);
       return bitPosArray;
   }
   while(num>0){
       b+= 1;
       if(num%2==1){
          bitPosArray.push_back(b);
       }
       num /= 2;
   }
   for(auto i= bitPosArray.begin() ;i != bitPosArray.end() ; ++i){
        *i = b - (*i) + 1;
    }
    bitPosArray.push_back(bitPosArray.size());
   reverse(begin(bitPosArray), end(bitPosArray));
   return bitPosArray;
}
int main(){

    long long int number;
    cout << "Enter the number : ";
    cin >> number;
    vector<int>BitPos = bitPos(number);
    cout << "number of bits up : "<< BitPos[0] << endl;
    for(auto i= BitPos.begin()+1 ;i != BitPos.end() ; ++i){
        cout << *i << "\t";
    }
    cout << endl;
    return 0;
}