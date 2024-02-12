#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left=0,right=0;
    int maxi=INT_MIN;
    long long int sum=0;
    int n=a.size();
    while(right<n){
        sum+=a[right];
        while(left<=right  && sum>k){
            sum-=a[left];
            left++;
        }
        if(sum==k){
            maxi=max(maxi,right-left+1);
        }
        right++;
    }
    return maxi;
}
//TC O(a.size()) 
