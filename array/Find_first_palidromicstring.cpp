 bool palidrome(string st){
       int n=st.length();
       int s=0,e=n-1;
       while(s<e){
           if(st[s]!=st[e]){
               return false;
           }
           else{
               s++;
               e--;
           }
       }
       return true;
   }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
               if(palidrome(words[i])) return words[i];
        }
        return "";   
    }

