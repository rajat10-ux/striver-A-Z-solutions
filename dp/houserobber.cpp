int helperonerecursion(vector<int>&nums,int index){
    if(index>=nums.size()){
        return 0;
    }
    int op1=nums[index]+helperonerecursion(nums,index+2);
    int op2=0+helperonerecursion(nums,index+1);
    return max(op1,op2);
}
int secondhelper(vector<int>&nums,int index,vector<int>&dp){
    if(index>=nums.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int op1=nums[index]+secondhelper(nums,index+2,dp);
    int op2=0+secondhelper(nums,index+1,dp);
    dp[index]=max(op1,op2);
    return dp[index];
}
int thirdhelper(vector<int>&nums){
    int n=nums.size();
vector<int>dp(n,-1);
dp[n-1]=nums[n-1];
for(int i=n-2;i>=0;i--){
    int temp=0;
    if(i+2<n){
        temp=dp[i+2];
    }
    int op1=nums[i]+temp;
    int op2=0+dp[i+1];
    dp[i]=max(op1,op2);
}
return dp[0];
}
int fourthhelperspace(vector<int>&nums){
      int n=nums.size();
// dp[n-1]=nums[n-1];
int prev=nums[n-1],curr=0,next=0;
for(int i=n-2;i>=0;i--){
    int temp=0;
    if(i+2<n){
        temp=next;
    }
    int op1=nums[i]+temp;
    int op2=0+prev;
    curr=max(op1,op2);
    next=prev;
    prev=curr;
}
return prev;
}
int rob(vector<int>& nums) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
        int index=0;
        int n=nums.size();
        vector<int>dp(n+1,-1);
        // int ans=helperonerecursion(nums,index);
        //int ans=secondhelper(nums,index,dp);
        // int ans=thirdhelper(nums);
        int ans=fourthhelperspace(nums);
        return ans;
}
