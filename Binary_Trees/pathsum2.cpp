void solve(TreeNode* root, int targetSum,int sum,vector<int>ds,vector<vector<int>>&ans){
    if(root==NULL){
        return;
    }
    sum+=root->val;
    ds.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
         if(sum==targetSum){
            ans.push_back(ds);
         }
         else{
            return;
         }
    }
    solve(root->left,targetSum,sum,ds,ans);
    solve(root->right,targetSum,sum,ds,ans);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
         vector<vector<int>>ans;
         vector<int>ds;
         int sum=0;
         solve(root,targetSum,sum,ds,ans);
         return ans;   
    }
