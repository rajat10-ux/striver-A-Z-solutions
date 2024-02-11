void rotateMatrix(vector<vector<int>> &arr){
	int n=arr.size();
	int m=arr[0].size();
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
	for(i=0;i<n;i++){
		reverse(arr[i].begin(),arr[i].end());
	}
}
//TC O(N*M)
