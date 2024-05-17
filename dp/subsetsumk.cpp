bool helper(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return arr[0]==target;
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool op1=helper(ind-1,target,arr,dp);
    bool op2=false;
    if(target>=arr[ind]) op2=helper(ind-1,target-arr[ind],arr,dp);
    dp[ind][target]=op1 || op2;
    return dp[ind][target];
}
bool secondhelper(int target,vector<int>&arr){
    vector<vector<bool>>dp(arr.size()+1,vector<bool>(target+1,0));
    for(int i=0;i<arr.size();i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
               bool op1=dp[i-1][j];
               bool op2=false;
               if(j>=arr[i]) op2=dp[i-1][j-arr[i]];
               dp[i][j]=op1 || op2;
        }
    }
    return dp[n-1][target];
}
bool thirdhelper(int target,vector<int>&arr){
    //vector<vector<bool>>dp(arr.size()+1,vector<bool>(target+1,0));
    vector<bool>prev(target+1,0);
    vector<bool>curr(target+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
               bool op1=prev[j];
               bool op2=false;
               if(j>=arr[i]) op2=prev[j-arr[i]];
               curr[j]=op1 || op2;
        }
        prev=curr;
    }
    return curr[target];
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // int ind=arr.size()-1;
        // vector<vector<int>>dp(ind+1,vector<int>(sum+1,-1));
        // bool ans=helper(ind,sum,arr,dp);
        // return ans;
        return thirdhelper(sum,arr);
    }
