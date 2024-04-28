#include<bits/stdc++.h>
using namespace std;
void findsub(int ind,vector<char>&ds,string st,int n){
if(ind==n){
        for(auto it:ds){
                cout<<it<<" ";
        }
        if(ds.size()==0){
                cout<<"{}";
        }
        cout<<endl;
        return;
}
ds.push_back(st[ind]);
findsub(ind+1,ds,st,n);
ds.pop_back();
findsub(ind+1,ds,st,n);
}
int main(){
string st="abc";
vector<char>ds;
findsub(0,ds,st,3);
return 0;
}