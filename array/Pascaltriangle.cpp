vector<int>helper(int n){
    vector<int>ans;
    long long res=1;
    ans.push_back(1);
    for(int i=1;i<n;i++){
        res=res*(n-i);
        res=res/(i);
        ans.push_back(res);
    }
    return ans;
}
vector<vector<int>> pascalTriangle(int N) {
  vector<vector<int>>ans;
  for(int i=1;i<=N;i++){
      vector<int>temp=helper(i);
      ans.push_back(temp);
  }
  return ans;
}
//TC O(N*N) SC O(1)
