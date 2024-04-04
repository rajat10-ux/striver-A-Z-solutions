int countRev (string s)
{
    int n=s.length();
    if(n&1)return  -1;
    int ans=0;
    stack<int>st;
    for(auto ch:s){
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int count=0;
    while(!st.empty()){
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b){
            count+=1;
        }
        else{
            count+=2;
        }
    }
    return count;
}
