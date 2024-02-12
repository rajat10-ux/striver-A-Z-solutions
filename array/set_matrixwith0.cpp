#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int colm=1,i,j;
	for(i=0;i<n;i++){
		if(matrix[i][0]==0) colm=0;
		for(j=1;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0]=matrix[0][j]=0;
			}
		}
	}
	for(i=n-1;i>=0;i--){
		for(j=m-1;j>=1;j--){
			if(matrix[i][0]==0 || matrix[0][j]==0){
				matrix[i][j]=0;
			}
		}
		if(colm==0) matrix[i][0]=0;
	}
	return matrix;
}
//TC O(N*M)
