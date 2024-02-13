#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    map<int,int>mp;
    int xr=0,count=0;
    int n=a.size();
    mp[xr]++;
    for(int i=0;i<n;i++){
      xr=xr^a[i];
      int rem=xr^b;
      count+=mp[rem];
      mp[xr]++;
    }
    return count;
}
//TC O(N) SC O(N)
