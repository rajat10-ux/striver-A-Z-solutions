#include<bits/stdc++.h>
int helper(vector<int>&arr,int m){
    int student=1;
    long long count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+count<=m){
            count+=arr[i];
        }
        else{
            student+=1;
            count=arr[i];
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(helper(arr,mid)<=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    return findPages(a,a.size(),k);
}
