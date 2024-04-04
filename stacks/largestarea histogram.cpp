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
//     for(int i=0;i<prev.size();i++){
//     if(prev[i]==-1){
//         prev[i]=prev.size();
//     }
//   }
  
  int maxi=INT_MIN;
  for(int i=0;i<heights.size();i++){
    int width=next[i]-prev[i]-1;
    int length=heights[i];
    int currarea=width*length;
    maxi=max(maxi,currarea);
  }    
  return maxi;
}
