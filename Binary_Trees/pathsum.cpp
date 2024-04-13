bool solve(TreeNode*root,int target,int sum){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(root==NULL){
        return false;
    }
      sum+=root->val;
    if(root->left==NULL && root->right==NULL){
        if(sum==target){
            return true;
        }
        else{
            return false;
        }
    }
    bool leftans=solve(root->left,target,sum);
    bool rightans=solve(root->right,target,sum);
    return leftans || rightans;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=solve(root,targetSum,sum);
        return ans;
    }
