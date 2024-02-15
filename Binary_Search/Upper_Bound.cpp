int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int s=0,e=n-1,ans=n;
	int mid=s+(e-s)/2;
	while(s<=e){
		if(arr[mid]>x){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
//TC O(NLOGN)
