   int sum(Node*root){
       if(root==NULL) return 0;
       if(root->left==NULL && root->right==NULL){
            int temp=root->data;
            root->data=0;
            return temp;
       }
       int ls=sum(root->left);
       int rs=sum(root->right);
       int temp=root->data;
       root->data=ls+rs;
       return root->data+temp;
   }
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
