//pressceeor in bst
Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node*curr=root;
        Node*ans=NULL;
        while(curr){
            if(curr->data>x->data){
                ans=curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return ans;
}
// succesort in bst
 Node*findsucc(Node*root,int val){
        Node*curr=root;
        Node*ans=NULL;
        while(curr){
            if(curr->key > val){
                ans=curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return ans;
    }
