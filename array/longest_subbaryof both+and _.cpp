#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    map<int,int>mp;
    int sum=0;
    int maxi=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxi=max(maxi,i+1);
        }
        int res=sum-k;
        if(mp.find(res)!=mp.end()){
            int len=i-mp[res];
            maxi=max(maxi,len);
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }
    return maxi;
}
// TC O(NLOGN) 
// SC O(N)
