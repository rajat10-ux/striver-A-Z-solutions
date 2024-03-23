#include<bits/stdc++.h>
using namespace std;
void subse(int ind,string &s,vector<int>&ds,int n){
        if(ind==n){
                for(auto it:ds){
                        cout<<char(it)<<" ";
                } 
                cout<<endl;
                return;
        }
        ds.push_back(s[ind]);
        subse(ind+1,s,ds,n);
        ds.pop_back();
        subse(ind+1,s,ds,n);
}
int main(){
vector<int>ds;
string s="abc";
subse(0,s,ds,3);
return 0;
}