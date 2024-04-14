bool isSameTree(TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(p==NULL && q==NULL){
            return true;
        } 
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p!=NULL && q!=NULL){
            bool left=isSameTree(p->left,q->left);
            bool right=isSameTree(p->right,q->right);
            if(left==true && right==true && p->val==q->val){
                return true;
            }
        }
        return false;
    }
