   string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
        string ans;
        stack<char>st;
        for(int i=0;i<num.size();i++){
            if(k>0){
            while(!st.empty() && st.top()>num[i]){
                st.pop();
                k--;
                if(k==0) break;
            }
        }
        st.push(num[i]);
        }
        if(k>0){
            while(!st.empty() && k){
                st.pop();
                k--;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0')
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans==""?"0":ans;
    }
