#include <bits/stdc++.h> 
void helper(int ind,vector<int>&arr,vector<vector<int>>&ans,int n){
 if(ind==n){
     ans.push_back(arr);
     return;
 }
 for(int i=ind;i<n;i++){
     swap(arr[ind],arr[i]);
     helper(ind+1,arr,ans,n);
     swap(arr[ind],arr[i]);
 }
}
vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>>ans;
    helper(0,vec,ans,size);
    return ans;
}
