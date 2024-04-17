int ans=0;
void path(TreeNode* root, long long int sum){
if(root==0) return;
if(root->val==sum)  ++ans;
path(root->left,sum-root->val);
path(root->right,sum-root->val);
}
int pathSum(TreeNode* root, int targetSum) {
            if(root){
                path(root,targetSum);
                pathSum(root->left,targetSum);
                pathSum(root->right,targetSum);
            }
            return ans;
}
