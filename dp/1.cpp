#include<bits/stdc++.h>
using namespace std;
// solve by memoiztion
int solve(int n,int &k,vector<int>&dp){
        if(n==1){
                return k;
        }
        if(n==2){
                return k+k*(k-1);
        }
        if(dp[n]!=-1){
                return dp[n];
        }
        int op1=(solve(n-1,k,dp))*(k-1);
        int op2=(solve(n-2,k,dp))*(k-2);
        dp[n]=op1+op2;
        return dp[n];
}
//solve by tablutaion
int secondmethod(int n,int k){
        vector<int>dp(n+1,-1);
        dp[1]=k;
        dp[2]=k+k*(k-1);
        for (int  i = 3; i <=n; i++)
        {
                dp[i]=(dp[i-1]+dp[i-2])*(k-1);
        }
        return dp[n];
}
int solvebyspaceoptimise(int n,int&k){
        int prev2=k;
        int prev1=k+k*(k-1);
        if(n==1){
                return prev2;
        }
        if(n==2){
                return prev1;
        }
        int curr;
        for(int i=3;i<=n;i++){
                curr=(prev1+prev2)*(k-1);
                prev2=prev1;
                prev1=curr;
        }
        return curr;
}
int main(){
        int n=3;
        int k=2;
        // vector<int>dp(n+1,-1);
       // int ans=solve(n,k,dp);
       //int ans=secondmethod(n,k);
        int ans=solvebyspaceoptimise(n,k);
        cout<<"ans="<<ans;
return 0;
}