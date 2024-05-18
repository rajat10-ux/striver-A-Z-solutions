void dfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&ans,
int color,int incolor,int delrow[],int delcol[]){
ans[row][col]=color;
int n=image.size();
int m=image[0].size();
for(int i=0;i<4;i++){
    int nrow=row+delrow[i];
    int ncol=col+delcol[i];
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==incolor && ans[nrow][ncol]!=color){
        dfs(nrow,ncol,image,ans,color,incolor,delrow,delcol);
    }
}
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int incolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,incolor,delrow,delcol);
        return ans;
    }
