  int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // r c t
 vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ccol=c+dcol[i];
                if(nrow>=0 && nrow<n && ccol>=0 && ccol<m && vis[nrow][ccol]!=2 && grid[nrow][ccol]==1){
                    q.push({{nrow,ccol},t+1});
                    vis[nrow][ccol]=2;
                }
            }
        }
                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
