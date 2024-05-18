    void helper(int node,vector<int> adj[],int vis[],vector<int>&ans){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                helper(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        int start=0;
        vector<int>ans;
        helper(start,adj,vis,ans);
        return ans;
    }
