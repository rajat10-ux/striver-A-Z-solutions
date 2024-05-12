int helper(int day,int last, vector<vector<int>> &points,vector<vector<int>>&dp){
  if(day==0){
    int maxi=0;
    for(int task=0;task<3;task++){
      if (task != last) {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }
  if(dp[day][last]!=-1){
    return dp[day][last];
  }
  int maxi=0;
  for(int task=0;task<3;task++){
    if(task!=last){
      int point=points[day][task]+helper(day-1,task,points,dp);
      maxi=max(maxi,point);
    }
  }
  dp[day][last]=maxi;
  return dp[day][last];
}
int secondhelper(vector<vector<int>>&points,int n){
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int thirdhelper(vector<vector<int>>&points,int n){
    vector<int>next(4,0);
    vector<int>curr(4,0);
    next[0]=max(points[0][1],points[0][2]);
    next[1]=max(points[0][0],points[0][2]);
    next[2]=max(points[0][0],points[0][1]);
    next[3]=max(points[0][1],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            curr[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+next[task];
                    curr[last]=max(curr[last],point);
                }
            }
        }
        next=curr;
    }
    return next[3];
}
int maximumPoints(vector<vector<int>>& points, int n) {
//  vector<vector<int>>dp(n+1,vector<int>(4,-1));
// return helper(n-1,3,points,dp);
int ans=thirdhelper(points,n);
return ans;
    }
