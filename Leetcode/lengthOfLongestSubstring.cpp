#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> alpha;
        int max=0;
        for(int i=0,j=0;i < s.size() ; ){
            if(alpha.find(s[i]) == alpha.end()){
                alpha.insert(s[i]);
                i++;
                if(max < alpha.size()){
                    max = alpha.size();
                }
            }else
            {
                alpha.erase(s[j]);
                j++;
            }
        }
        return max;
}

int main(){
   string s;
   getline(cin , s);
   cout << lengthOfLongestSubstring(s) << endl;
   return 0;
}