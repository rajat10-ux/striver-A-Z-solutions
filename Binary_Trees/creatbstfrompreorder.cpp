TreeNode*helper(vector<int>& pre,int mini,int maxi,int &i){
    if(i>=pre.size()) return nullptr;
    TreeNode*root=NULL;
    if(pre[i]>mini && pre[i]<maxi){
        root=new TreeNode(pre[i++]);
        root->left=helper(pre,mini,root->val,i);
        root->right=helper(pre,root->val,maxi,i);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return helper(preorder,mini,maxi,i);
    }
