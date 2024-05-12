    int solve(int i,int j,vector<vector<int>>& obstacleGrid
    ,int n,int m,vector<vector<int>>&dp)
    {
        if(i>=n||j>=m||j<0||i<0||obstacleGrid[i][j]==1) 
        {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1&&j==m-1)
      {
          return 1;
      }
        int right=0,down=0;
        right=solve(i,j+1,obstacleGrid,n,m,dp);
        down=solve(i+1,j,obstacleGrid,n,m,dp);
        return dp[i][j]=right+down; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n=obstacleGrid.size();
         int m=obstacleGrid[0].size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         return solve(0,0,obstacleGrid,n,m,dp);
    } 
