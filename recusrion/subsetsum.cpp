#include<bits/stdc++.h>
void helper(int ind,vector<int>&num,vector<int>&ans,int sum){
	if(ind==num.size()){
		ans.push_back(sum);
		return;
	}
	helper(ind+1,num,ans,sum+num[ind]);
	helper(ind+1,num,ans,sum);
}
vector<int> subsetSum(vector<int> &num){
	vector<int>ans;
	helper(0,num,ans,0);
	sort(ans.begin(),ans.end());
	return ans;
}
