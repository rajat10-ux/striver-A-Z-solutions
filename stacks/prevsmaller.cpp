 vector<int> leftSmaller(int n, int arr[]){
        vector<int>ans;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()>=arr[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        return ans;
    }
