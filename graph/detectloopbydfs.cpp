 bool detect2bydfs(int node,int parent,vector<int>adj[],int vis[]){
        vis[node]=1;
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                if(detect2bydfs(nbr,node,adj,vis)==true)
                    return true;
            }
               else if(nbr!=parent)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // int vis[V]={0};
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(detect(i,adj,vis)==true){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect2bydfs(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
