bool redudantback(string &s){
        stack<char>st;
        for (int  i = 0; i < s.size(); i++)
        {
                char ch=s[i];
                if(ch=='(' || ch=='+'|| ch=='-' || ch=='*' || ch=='/'){
                        st.push(ch);
                }
                else if(ch==')'){
                        int count=0;
                        while(st.top()!='('){
                                char ch=st.top();
                                if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
                                        count++;
                                }
                                st.pop();
                        }
                        st.pop();
                        if(count==0){
                                return true;
                        }
                }
        }
        return false;
}
