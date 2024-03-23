#include<bits/stdc++.h>
using namespace std;
void subs(int ind,vector<int>&ds,int*arr,int n){
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
        ds.push_back(arr[ind]);
        subs(ind+1,ds,arr,n);
        ds.pop_back();
        subs(ind+1,ds,arr,n);
}
int main(){
vector<int>ds;
int arr[3]={1,2,3};
subs(0,ds,arr,3);
return 0;
}