bool detect(int src,vector<int>adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(auto nbr:adj[a]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push({nbr,a});
                }
                else if(b!=nbr){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
