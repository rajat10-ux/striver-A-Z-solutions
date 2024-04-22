 class info {
     public:
    int mini;
    int maxi;
    int size;
    bool isbst;
};
    info solve(Node* root, int& ans){
       if(root == NULL) return { INT_MAX, INT_MIN, 0, 1 };
       info left = solve(root->left, ans);
       info right = solve(root->right, ans);
       info currNode;
       currNode.size = left.size + right.size + 1;
       currNode.maxi = max(root->data, right.maxi);
       currNode.mini = min(root->data, left.mini);
       if(left.isbst && right.isbst && root->data > left.maxi &&
       root->data < right.mini)
       currNode.isbst = true;
       else currNode.isbst = false;
       if(currNode.isbst){
           ans = max(ans, currNode.size);
       }
       return currNode;
    }
    int largestBst(Node *root)
    {
        int maxsize = 0;
        info temp = solve(root, maxsize);
        return maxsize;
    }
