#include<bits/stdc++.h>
using namespace std;
void summe(int ind,vector<int>&ds,int*arr,int s,int sum,int n){
        if(ind==n){
                if(s==sum){
                        for(auto it:ds){
                                cout<<it<<" ";
                        }
                        cout<<endl;
                }
                return;
        }
        ds.push_back(arr[ind]);
        s+=arr[ind];
        summe(ind+1,ds,arr,s,sum,n);
        s-=arr[ind];
        ds.pop_back();
        summe(ind+1,ds,arr,s,sum,n);
}
int main(){
int arr[4]={2,3,6,7};
vector<int>ds;
summe(0,ds,arr,0,7,4);
return 0;
}