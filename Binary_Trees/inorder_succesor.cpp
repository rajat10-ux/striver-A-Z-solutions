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
