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
