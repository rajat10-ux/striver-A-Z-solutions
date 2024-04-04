vector<int>nextsmallerelement(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size());
    st.push(-1);
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int>prevsmallerelement(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size());
    st.push(-1);
    int n=arr.size();
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
  vector<int>next=nextsmallerelement(heights);
  vector<int>prev=prevsmallerelement(heights);
  for(int i=0;i<next.size();i++){
    if(next[i]==-1){
        next[i]=next.size();
    }
  }
  int maxi=INT_MIN;
  for(int i=0;i<heights.size();i++){
    int width=next[i]-prev[i]-1;
    int length=heights[i];
    int currarea=width*length;
    maxi=max(maxi,currarea);
  }    
  return maxi;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=INT_MIN;
        vector<int>ans(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<ans.size();j++){
                if(matrix[i][j]=='1'){
                    ans[j]++;
                }
                else{
                    ans[j]=0;
                }
            }
            maxi=max(maxi,largestRectangleArea(ans));
        }
        return maxi;      
    }
