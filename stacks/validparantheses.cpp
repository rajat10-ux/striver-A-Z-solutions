bool isvalid(string &s){
stack<char>st;
for (int  i = 0; i < s.length(); i++)
{
        char ch=s[i];
        if(ch=='[' || ch=='{' || ch=='('){
                st.push(ch);
         }
         else {
                if(!st.empty()){
                        if((st.top()=='[' && s[i]==']') || (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}')){
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
