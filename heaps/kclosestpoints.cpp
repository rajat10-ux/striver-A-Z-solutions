class mycomp{
 public:
 bool operator()(pair<int,int>&a,pair<int,int>&b){
    int first=a.first*a.first +a.second*a.second;
    int second=b.first*b.first + b.second*b.second;
    return first > second;
 }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<vector<int>>ans;
       priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
       for(auto it:points){
        pq.push(make_pair(it[0],it[1]));
       }   
       while(!pq.empty() && k--){
        auto topans=pq.top();
        ans.push_back({topans.first,topans.second});
        pq.pop();
       }
       return ans;
    }
