  int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len=i-st.top();
                    maxi=max(maxi,len);
                }
            }
        }
        return maxi;
    }
