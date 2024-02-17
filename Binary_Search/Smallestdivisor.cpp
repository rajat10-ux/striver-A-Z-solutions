#include<bits/stdc++.h>
int sumeofval(vector<int>&arr,int val){
	int n=arr.size();
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=ceil((double)arr[i]/(double)val);
	}
	return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	if(arr.size()>limit) return -1;
	int maxi=INT_MIN;
	for(int i=0;i<arr.size();i++){
		maxi=max(maxi,arr[i]);
	}
	int low=1,high=maxi;
	while(low<=high){
		int mid=(low+high)/2;
		if(sumeofval(arr,mid)<=limit){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
}
//TC (MIN(LOGN)*N)
