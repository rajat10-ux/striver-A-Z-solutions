#include<bits/stdc++.h>
int majorityElement(vector<int>v) {
	int n=v.size();
	// unordered_map<int,int>mp;
	// for(int i=0;i<n;i++){
	// 	mp[arr[i]]++;
	// }
	// int ans=0;
	// for(auto it:mp){
	// 	if(it.second>n/2){
	// 		ans=it.first;
	// 	}
	// }
	// return ans;
	int cnt=0,el;
	for(int i=0;i<n;i++){
		if(cnt==0){
			cnt=1;
			el=v[i];
		}
		if(el==v[i]) cnt++;
		else cnt--;
	}
	int cnt1=0;
	for(int i=0;i<n;i++){
		if(el==v[i]) cnt1++;
	}
	if(cnt1>n/2){
		return el;
	}
	return -1;
}
