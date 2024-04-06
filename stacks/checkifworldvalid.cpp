 bool isValid(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        if(s[0]!='a') return false;
        stack<char>st;
        for(auto ch:s){
            if(ch=='a')
            st.push(ch);
            else if(ch=='b'){
                if(!st.empty() && st.top()=='a'){
                    st.push(ch);
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
//tc o(n)
