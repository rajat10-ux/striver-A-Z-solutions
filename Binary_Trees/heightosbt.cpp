   int maxDepth(TreeNode* root) {
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
       if(root==NULL){
        return 0;
       }   
       int a=maxDepth(root->left);
       int b=maxDepth(root->right);
       return max(a,b)+1;
    }
