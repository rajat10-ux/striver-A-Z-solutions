void helper(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&arr,int sum){
    if(sum==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>sum) break;
        ds.push_back(arr[i]);
        helper(i+1,ds,ans,arr,sum-arr[i]);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
         vector<int>ds;
         helper(0,ds,ans,candidates,target);
         return ans;
    }
