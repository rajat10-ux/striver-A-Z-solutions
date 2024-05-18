    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        int vis[v]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
