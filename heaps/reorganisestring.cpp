class Info{
public:
char val;
int count;
Info(char val,int count){
    this->val=val;
    this->count=count;
}
};
class compare{
public:
bool operator()(Info*a,Info*b){
    return a->count < b->count;
}
};
    string reorganizeString(string s) {
       int freq[26]={0};
       for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
       } 
       priority_queue<Info*,vector<Info*>,compare>pq;
       for(int i=0;i<26;i++){
        if(freq[i]>0){
            Info *temp=new Info(i+'a',freq[i]);
            pq.push(temp);
        }
       }
       string ans="";
       while(pq.size()>1){
        Info*first=pq.top();pq.pop();
        Info*second=pq.top();pq.pop();
        ans.push_back(first->val);first->count--;
        ans.push_back(second->val);second->count--;
        if(first->count>0) pq.push(first);
         if(second->count>0) pq.push(second);
       }
       if(pq.size()==1){
         Info*first=pq.top();pq.pop();
             ans.push_back(first->val);first->count--;
             if(first->count!=0) return "";
       }
       return ans;
    }
