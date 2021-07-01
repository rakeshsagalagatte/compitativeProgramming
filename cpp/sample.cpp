#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {

    vector< vector<int> > subarray(90);
    int t=0,same=1;
    sort(a.begin() , a.end());
    subarray[0].push_back(a[0]);
    for(int i=1;i< a.size();i++){
        if((a[i] - a[i-1]) > 1 || same == 2){
            t += 1;
            subarray[t].push_back(a[i]);
            same  = 1;
            continue;
        }

        if(subarray[t][0] != a[i] && same < 2){
            same = same + 1;
        }else if(subarray[t][0] != a[i] && same == 2){
            same = 1;
            t += 1;
            subarray[t].push_back(a[i]);
            continue;
        }

        subarray[t-1].push_back(a[i]);
    }
    int maxlen=subarray[0].size();
    for(int i=1;i<subarray.size();i++){
        if(maxlen < subarray[i].size()){
            maxlen = subarray[i].size();
        }
    }

    return maxlen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    cout << result << "\n";

    fout.close();

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

