  int helper(vector<int>& height, int n, int k,int i,vector<int>&dp){
      if(i==0) return 0;
      int ans=INT_MAX,jump=0;
      if(dp[i]!=-1){
          return dp[i];
      }
      for(int j=1;j<=k;j++){
          if(i-j>=0){
          jump=helper(height,n,k,i-j,dp)+abs(height[i]-height[i-j]);
          }
         ans=min(ans,jump);
      }
      dp[i]=ans;
      return dp[i];
  }
  int secondhelper(vector<int>&height,int n,int k){
      vector<int>dp(n+1,0);
      for(int i=1;i<n;i++){
            int ans=INT_MAX;
            for(int j=1;j<=k;j++){
              if(i-j>=0){
              int jump=dp[i-j]+abs(height[i]-height[i-j]);
                    ans=min(ans,jump);
              }
           }
         dp[i]=ans;
      }
      return dp[n-1];
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        //vector<int>dp(n+1,-1);
       // int ans=helper(height,n,k,n-1,dp);
           int ans=secondhelper(height,n,k);
        return ans;
    }
