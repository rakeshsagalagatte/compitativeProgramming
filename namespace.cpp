#include <iostream>
#include <string>
    using namespace std;

    

    int main () {
string str1;
getline(cin,str1);
int num =0;
for(int i =0;i < str1.length();i++){
   if(isdigit(str1[i])){
      num += 1;
   }
}
cout << num;
       return 0;

    }