int helper(vector<int>&nums,int amount){
    if(amount==0) return 0;
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int recans=0;
        if(amount-nums[i]>=0){
            recans=helper(nums,amount-nums[i]);
            if(recans!=INT_MAX){
            int ans=1+recans;
            mini=min(ans,mini);
            }
        }
    }
    return mini;
}
int secondhelper(vector<int>&nums,int amount,vector<int>&dp){
      if(amount==0) return 0;
    int mini=INT_MAX;
    if(dp[amount]!=-1){
        return dp[amount];
    }
    for(int i=0;i<nums.size();i++){
        int recans=0;
        if(amount-nums[i]>=0){
            recans=secondhelper(nums,amount-nums[i],dp);
            if(recans!=INT_MAX){
            int ans=1+recans;
            mini=min(ans,mini);
            }
        }
    }
    dp[amount]=mini;
    return dp[amount];
}
int thirdhelper(vector<int>&nums,int amount){
       vector<int>dp(amount+1,0);
    for(int val=1;val<=amount;val++){
            int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
        int recans=0;
        if(val-nums[i]>=0){
           int recans=dp[val-nums[i]];
            if(recans!=INT_MAX){
            int ans=1+recans;
            mini=min(ans,mini);
            }
        }
    }
    dp[val]=mini;
    }
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        // int ans=helper(coins,amount;
       // vector<int>dp(amount+1,-1);
        int ans=thirdhelper(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
