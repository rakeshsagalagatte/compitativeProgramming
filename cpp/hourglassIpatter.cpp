#include <bits/stdc++.h>
#include<string>
#include<iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int> > arr) {
    int row = arr.size(), counte =0, maxe = INT_MIN,c=0,j=0,trc=0;
    for(int i=0; i < row - 2;i++){
        int col = arr[i].size();
        c=0;
        counte =0;
        for(j=trc; c < 3; j++){
            counte += arr[i][j] + arr[i+2][j];
            c++;
        }
        counte += arr[i+1][trc+1];
        //cout << counte << " i= " << i << endl;
        if(maxe < counte ){
            maxe = counte ;
        }
        if(i+1 == row-2 && j != col-1){
            i=-1;
            trc++;
        }
    }
    return maxe;
}

int main()
{

    vector<vector<int>> arr(6);
    
    for (int i = 0; i < 6; i++) {
        arr[i]= vector<int>(6,0);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    } 

    int result = hourglassSum(arr);

    cout << result << "\n";



    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
