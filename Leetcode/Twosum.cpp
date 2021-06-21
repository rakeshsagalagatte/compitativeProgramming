#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    //sort(nums.begin(), nums.end());
    int i=0;
    vector<int> v;
    // while(i < nums.size() && nums[i] < target){
    //     i++;
    // }
    for(int j=0;j<nums.size();j++){
        for(int k=j+1;k<nums.size();k++){
            if((nums[j] + nums[k]) == target){
                v.push_back(j);
                v.push_back(k);
            }
        }
    }
    return v;
}

int main(){
    vector<int> nums;
    int N,target;
    cin >> N >> target;
    for(int i=0;i< N;i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    vector<int> res = twoSum(nums, target);
    for(int i=0;i < res.size();i++){
        cout << res[i] << endl;
    }
    return 0;
}