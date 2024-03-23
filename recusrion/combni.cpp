void helper(int ind,vector<int>&ds,vector<int>&arr,  vector<vector<int>>&ans ,int sum){
    int n=arr.size();
    if(ind==n){
        if(sum==0){
            ans.push_back(ds);
        }
        return;
    }
    if(sum>=arr[ind]){
    ds.push_back(arr[ind]);
    helper(ind,ds,arr,ans,sum-arr[ind]);
    ds.pop_back();
    }
       helper(ind+1,ds,arr,ans,sum);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>ds;
       helper(0,ds,candidates,ans,target);
       return ans;
    }
