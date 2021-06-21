#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool static columsort(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v1[0];
    }
    
    string arrangeWords(string text) {
        vector<string> words;
        string word;
        vector< vector <int> > Len;
        vector<int> v1;
        text[0] = tolower(text[0]);
        stringstream stre(text);
        int k=0;
        
        while(stre >> word){
            words.push_back(word);
            v1.push_back(word.size());
            v1.push_back(k);
            Len.push_back(v1);
            v1.clear();
            k++;
        }
        
        sort(Len.begin(), Len.end());
        string mergeing="";
        for(int i=0;i < k;i++){
            mergeing += words[Len[i][1]];
            
            if(i!= k-1){
                mergeing += " ";
            }
        }
        mergeing[0] = toupper(mergeing[0]);
        Len.clear();
        words.clear();
        return mergeing;
    }
    
};

// bool Solution::columsort(const vector<int>& v1, const vector<int>& v2){
//         return v1[0] < v1[0];
//     }

int main()
{
    string text;
    getline(cin, text);
    Solution sol;
    string rearraged = sol.arrangeWords(text);
    cout << rearraged << endl;
    // sol.arrangeWords(text);
    return 0;
}