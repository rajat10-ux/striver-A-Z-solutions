#include<bits/stdc++.h>
using namespace std;
int main(){
string str="ababc";
int freq[26]={0};
queue<int>q;
for(int i=0;i<str.length();i++){
        char ch=str[i];
        freq[ch-'a']++;
        q.push(ch);
while (!q.empty())
{
        char frontchar=q.front();
        if(freq[frontchar-'a']>1){
                q.pop();
        }
        else{
                cout<<frontchar<<" ";
                break;
        }
}
if(q.empty()){
        cout<<"#"<<" ";
}
}
return 0;
}