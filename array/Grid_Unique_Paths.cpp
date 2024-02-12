#include <bits/stdc++.h> 
int helper(int i,int j,int m,int n,vector<vector<int>>&dp){
	if(i==m-1 && j==n-1){
		return 1;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(i>=m || j>=n){
		return 0;
	}
	int help=helper(i+1,j,m,n,dp)+helper(i,j+1,m,n,dp);
	return help;
}
// int secondhelper(int m,int n){
//  	vector<vector<int>>dp(m+1,vector<int>(n+1,0));
// 	 int help=0,i,j;
// 	 for(i=m-1;i>0;i--){
// 		 for(j=n-1;j>0;j--){
// 			 help=dp[i+1][j]+dp[i][j+1];
// 		 }
// 	 }
// 	 return dp[0][0];
// }
int uniquePaths(int m, int n) {
	// Write your code here.
	// vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//	int ans=helper(0,0,m,n,dp);
	//   int a=m-n-2;
	//   int b=m-1;
//  int ans=secondhelper(m,n);
//  return ans;
int a=m+n-2;
int b=m-1;
double ans=1;
for(int i=1;i<=b;i++){
	ans=ans*(a-b+i)/i;
}
return int(ans);
}

