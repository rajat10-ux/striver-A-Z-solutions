#include <bits/stdc++.h> 
int helper(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int op1=grid[i][j]+helper(i-1,j,grid,dp);
    int op2=grid[i][j]+helper(i,j-1,grid,dp);
    dp[i][j]=min(op1,op2);
    return dp[i][j];
}
int secondhelper(vector<vector<int>>&grid){
        int n=grid.size();
    int m=grid[0].size();
     vector<vector<int>>dp(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(i==0 && j==0) dp[i][j]=grid[i][j];
             else{
                 int op1=grid[i][j];
                 if(i>0){
                     op1+=dp[i-1][j];
                 }
                 else op1+=1e9;
                 int op2=grid[i][j];
                 if (j > 0) {
                     op2 += dp[i][j - 1];
                 } else
                     op2 += 1e9;
                 dp[i][j] = min(op1, op2);
             }
         }
     }
     return dp[n-1][m-1];
}
int thirdhelper(vector<vector<int>>&grid){
        int n=grid.size();
    int m=grid[0].size();
    vector<int>next(m+1,0);
    vector<int>curr(m+1,0);
   //  vector<vector<int>>dp(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(i==0 && j==0) curr[j]=grid[i][j];
             else{
                 int op1=grid[i][j];
                 if(i>0){
                     op1+=next[j];
                 }
                 else op1+=1e9;
                 int op2=grid[i][j];
                 if (j > 0) {
                     op2 += curr[j - 1];
                 } else
                     op2 += 1e9;
                 curr[j] = min(op1, op2);
             }
         }
         next=curr;
     }
     return next[m-1];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   // int ans=helper(n-1,m-1,grid,dp);
    int ans=thirdhelper(grid);
    return ans;
}
