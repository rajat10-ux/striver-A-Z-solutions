#include <bits/stdc++.h> 
int helper(int i,int j,vector<vector<int>> &matrix,vector<vector<int>>&dp){
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=matrix[i][j]+helper(i-1, j, matrix,dp);
       int b=matrix[i][j]+helper(i-1, j-1, matrix,dp);
          int c=matrix[i][j]+helper(i-1, j+1, matrix,dp);
          dp[i][j]=max(a,max(b,c)); 
          return dp[i][j];
}
int secondhelper(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();
     vector<vector<int>>dp(m+1,vector<int>(n+1,0));
     for(int j=0;j<n;j++){
          dp[0][j]=matrix[0][j];
     }
     for(int i=1;i<m;i++){
         for(int j=0;j<n;j++){
                 int a=matrix[i][j]+dp[i-1][j];
           int b=matrix[i][j];
             if(j-1>=0) b+=dp[i-1] [j-1];
             else b+=-1e8;
          int c=matrix[i][j];
                 if(j+1<n) c+=dp[i-1][j+1];
                 else c+=-1e8;
          dp[i][j]=max(a,max(b,c)); 
         }
     }
     int maxi=-1e8;
         for(int j=0;j<n;j++){
        maxi=max(maxi,dp[m-1][j]);
    }
    return maxi;
}
int thirdhelper(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
     vector<int>next(n+1,0);
     vector<int>curr(n+1,0);
     for(int j=0;j<n;j++){
          next[j]=matrix[0][j];
     }
     for(int i=1;i<m;i++){
         for(int j=0;j<n;j++){
                 int a=matrix[i][j]+next[j];
           int b=matrix[i][j];
             if(j-1>=0) b+=next[j-1];
             else b+=-1e8;
          int c=matrix[i][j];
                 if(j+1<n) c+=next[j+1];
                 else c+=-1e8;
          curr[j]=max(a,max(b,c)); 
         }
         next=curr;
     }
     int maxi=-1e8;
         for(int j=0;j<n;j++){
        maxi=max(maxi,next[j]);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m=matrix.size();
    int n=matrix[0].size();
    // int maxi=-1e8;
    // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    // for(int j=0;j<n;j++){
    //     maxi=max(maxi,helper(m-1,j,matrix,dp));
    // }
    // return maxi;
    return thirdhelper(matrix);
}
