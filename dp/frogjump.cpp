  int helper(int i,vector<int>&arr,vector<int>&dp){
      if(i==0) return 0;
      if(dp[i]!=-1){
          return dp[i];
      }
      int left=helper(i-1,arr,dp)+abs(arr[i]-arr[i-1]);
      int right=INT_MAX;
      if(i>1){
      right=helper(i-2,arr,dp)+abs(arr[i]-arr[i-2]);
      }
       int ans=min(left,right);
      dp[i]=ans;
      return dp[i];
  }
  int secondhelper(vector<int>&arr,int n){
      vector<int>dp(n+1,0);
      for(int i=1;i<n;i++){
       int left=dp[i-1]+abs(arr[i]-arr[i-1]);
      int right=INT_MAX;
          if(i>1){
         right=dp[i-2]+abs(arr[i]-arr[i-2]);
         }
       int ans=min(left,right);
       dp[i]=ans;
      }
      return dp[n-1];
  }
  int thirdhelper(vector<int>&arr,int n){
         int prev=-1,curr=0;
         for(int i=1;i<n;i++){
       int left=curr+abs(arr[i]-arr[i-1]);
      int right=INT_MAX;
          if(i>1){
         right=prev+abs(arr[i]-arr[i-2]);
         }
       int ans=min(left,right);
          curr=ans;
          prev=curr;
      }
      return prev;
}
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
      //  vector<int>dp(n+1,-1);
    //    int ans=helper(n-1,height,dp);
        int ans=secondhelper(height,n);
        return ans;
    }
