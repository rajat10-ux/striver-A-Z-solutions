  bool knows(vector<vector<int>>&arr,int a,int b,int n){
        if(arr[a][b]==1)return true;
        else return false;
    }
    int celebrity(vector<vector<int> >&arr, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(knows(arr,a,b,n)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int value=st.top();
        int rowcount=0;
        for(int i=0;i<n;i++){
            if(arr[value][i]==0){
                rowcount++;
            }
        }
        if(rowcount!=n)return -1;
        int colcount=0;
        for(int i=0;i<n;i++){
            if(arr[i][value]==1){
                colcount++;
            }
        }
        if(colcount!=n-1) return -1;
        return value;
    }
