#include<bits/stdc++.h>
using namespace std;
// int solve(int capacity,int*weights,int*profit,int index,int n){
//  if(index>=n){
//         // if(weights[index]<=capacity){
//         //         return profit[index];
//         // }
//         // else{
//         //         return 0;
//         // }
//         return 0;
//  }
// int include=0;
// if(weights[index]<=capacity){
//         include=profit[index]+solve(capacity-weights[index],weights,profit,index+1,n);
// }
// int exclude=0+solve(capacity,weights,profit,index+1,n);
// int ans=max(include,exclude);
// return ans;
// }
//solve by mem and extra space
//int helperMem(int capacity,int *weights,int*profit,int index,int n,vector<vector<int>>&dp){
//     if(index>=n){
//         return 0;
//     }
//     if(dp[capacity][index]!=-1){
//         return dp[capacity][index];
//     }
//     int include=0;
// if(weights[index]<=capacity){
// include=profit[index]+helperMem(capacity-weights[index],weights,profit,index+1,n,dp);
// }
// int exclude=0+helperMem(capacity,weights,profit,index+1,n,dp);
// dp[capacity][index]=max(include,exclude);
// return dp[capacity][index];   
// }
// solve by tabulation bottom up
int secondhelp(int capacity,int*weights,int *profit,int n){
vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
for(int row=0;row<=capacity;row++){
        // here we have made row and index maked with zero
        dp[row][n]=0;
}
for(int i=0;i<=capacity;i++){
        for(int j=n-1;j>=0;j--){
  int include=0;
if(weights[j]<=i){
include=profit[j]+dp[i-weights[j]][j+1];
}
int exclude=dp[i][j+1];
dp[i][j]=max(include,exclude);
}
}
return dp[capacity][0];
}
int thirdhelp(int capacity,int *weights,int *profit,int n){
        vector<int>next(capacity+1,0);
        int i,j;
        for(j=n-1;j>=0;j--){
                for(i=capacity;i>=0;i--){
                        int include=0;
                         if(weights[j]<=i){
                                include=profit[j]+next[i-weights[j]];
                         }
                         int exclude=0+next[i];
                         next[i]=max(include,exclude);
                }
        }
        return next[capacity];
}
int main(){
int capacity=50;
int n=3;
int weights[]={10,20,30};
int profit[]={60,100,120};
int index=0;
vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
// int ans=helperMem(capacity,weights,profit,index,n,dp);
int ans=secondhelp(capacity,weights,profit,n);
int ans2=thirdhelp(capacity,weights,profit,n);
cout<<"ans="<<ans2<<endl;
return 0;
}