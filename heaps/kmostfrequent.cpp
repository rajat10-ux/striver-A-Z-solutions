#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:mp){
        pq.push(make_pair(it.second,it.first));
    }
    vector<int>ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
