vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool LtoR = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            Node* front = q.front();
            q.pop();
            int width = LtoR ? i : n - 1 - i;
            temp[width] = front->data;
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        LtoR = !LtoR;
        for(auto it:temp){
            ans.push_back(it);
        }
    }
    return ans;
    }
