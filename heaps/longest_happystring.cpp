class Info{
public:
char ch;
int count;
Info(char ch,int count){
    this->ch=ch;
    this->count=count;
}
};
class compare{
public:
bool operator()(Info a,Info b){
    return a.count < b.count;
}
};
string longestDiverseString(int a, int b, int c) {
        priority_queue<Info,vector<Info>,compare>pq;
        if(a>0){
            Info temp('a',a);
            pq.push(temp);
        }
          if(b>0){
            Info temp('b',b);
            pq.push(temp);
        }
        if(c>0){
            Info temp('c',c);
            pq.push(temp);
        }
        string ans="";
        while(pq.size()>1){
            Info first=pq.top();pq.pop();
            Info second=pq.top();pq.pop();
            if(first.count>=2){
                ans.push_back(first.ch);
                ans.push_back(first.ch);
                first.count-=2;
            }
            else{
                ans.push_back(first.ch);
                first.count--;
            }
            if(second.count>=2 && second.count>=first.count){
                ans.push_back(second.ch);
                ans.push_back(second.ch);
                second.count-=2;
            }
            else{
                ans.push_back(second.ch);
                second.count--;
            }
            if(first.count>0) pq.push(first);
            if(second.count>0) pq.push(second);
        }
        if(pq.size()==1){
            Info first=pq.top();pq.pop();
            if(first.count>=2){
                ans.push_back(first.ch);
                ans.push_back(first.ch);
                first.count-=2;
            }
            else{
                ans.push_back(first.ch);
                first.count--;
            }
        }
        return ans;
}
