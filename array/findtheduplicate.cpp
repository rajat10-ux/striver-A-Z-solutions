#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	//  sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++){
    //     if(arr[i]==arr[i+1]){
    //         return arr[i];
    //     }
    // }
  //TC O(NLOGN) 
    //Write your code here.
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int ans;
    for(auto it:mp){
        if(it.second>1){
            ans=it.first;
        }
    }
    return ans;
}
//TC O(N) SC O(N)
