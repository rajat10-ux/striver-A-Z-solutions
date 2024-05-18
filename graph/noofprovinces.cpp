void dfs(int node,vector<int>adjlist[],vector<int>&vis){
    vis[node]=1;
    for(auto nbr:adjlist[node]){
        if(!vis[nbr]){
            dfs(nbr,adjlist,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adjlist[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int>vis; 
        for(int i=0;i<n;i++) 
        {
            vis.push_back(0);
        } 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjlist,vis);
            }
        }
        return cnt;
    }
