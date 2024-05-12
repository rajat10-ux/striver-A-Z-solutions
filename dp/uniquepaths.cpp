int helper(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int op1=helper(i-1,j,dp);
    int op2=helper(i,j-1,dp);
    dp[i][j]=op1+op2;
    return dp[i][j];
}
int secondhelper(int m, int n){
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        dp[0][0]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                int first=0, second=0;
                if(i > 0)
                    first = dp[i-1][j];
                if(j>0)
                    second = dp[i][j-1];
                dp[i][j]=first+second;
            }
        }
        return dp[m][n];
}
int thirdhelper(int m,int n){
   vector<int> prev(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // int ans=helper(m-1,n-1,dp);
        //int ans=secondhelper(m-1,n-1);
       int ans=thirdhelper(m,n);
        return ans;
    }
