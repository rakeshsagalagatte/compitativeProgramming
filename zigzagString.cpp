#include<iostream>
#include<vector>
#include<string>

using namespace std;

string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows){
            ret += row;
            //cout << row << endl;
        } 
        return ret;
    }

int main(){
    string name;
    int numRows;
    cout << "Enter string : ";
    getline(cin, name);
    cout << "Enter the Rows : ";
    cin >> numRows;
    cout << "Original String : " << name << endl;
    cout << "After modification : " << convert(name, numRows) << endl;
    return 0;
}