int helper(int n,vector<int>&dp){
          if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=helper(n-1,dp)+helper(n-2,dp);
        return dp[n];
}
int secondhelper(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
     if(n==0) return dp[0];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int thirdhelper(int n){
    int prev=0,curr=1,ans;
    if(n==0) return 0;
    if(n==1) return 1;
    for(int i=2;i<=n;i++){
        ans=prev+curr;
        prev=curr;
        curr=ans;
    }
    return ans;
}
    int fib(int n) {
        // vector<int>dp(n+1,-1);
        // // return helper(n,dp);
        // return secondhelper(n);
        return thirdhelper(n);
    }
