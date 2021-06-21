#include <bits/stdc++.h>

using namespace std;

int compare(const void* a, const void* b){
    if((int*) a > (int*) b)
        return 1;
    else if((int*) a < (int*) b)
    {
        return -1;
    }
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    qsort(&nums1[0], nums1.size() , sizeof(int), compare);
    int n=nums1.size()+ nums2.size() + 1;
    if(n%2 == 0){
        int k = n/2;
        int j = nums1[k-1] + nums1[k];
        return (j/2);
    }
    return nums1[n/2]/2;
} 
int main(){
    vector<int> nums1;
    vector<int> nums2;
    int n,m;
    cin >> n >> m;
    for (int i=0; i < n;i++){
        int a ;
        cin >> a;
        nums1.push_back(a);
    }
    for (int i=0; i < m;i++){
        int a ;
        cin >> a;
        nums2.push_back(a);
    }
    double d =findMedianSortedArrays(nums1, nums2);
    cout << d << endl;
    return 0;
}
