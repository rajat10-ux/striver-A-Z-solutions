int heightofbt(TreeNode*root){
    if(root==NULL) return 0;
    return 1+max(heightofbt(root->left),heightofbt(root->right));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=heightofbt(root->left)+heightofbt(root->right);
        return max(op1,max(op2,op3));
    }
// second approach
pair<int,int>diameterfast(TreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=diameterfast(root->left);
    pair<int,int>right=diameterfast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second;
    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root){
if(root==NULL){
    return 0;
}
pair<int,int>res=diameterfast(root);
return res.first;
}
