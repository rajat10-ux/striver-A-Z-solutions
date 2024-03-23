#include<bits/stdc++.h>
using namespace std;
bool summe(int ind,vector<int>&ds,int*arr,int s,int sum,int n){
        if(ind==n){
                if(s==sum){
                        for(auto it:ds){
                                cout<<it<<" ";
                                return true;
                        }
                        cout<<endl;
                }
                return false;
        }
        ds.push_back(arr[ind]);
        s+=arr[ind];
       if(summe(ind+1,ds,arr,s,sum,n)==true){
          return true;
       }
        s-=arr[ind];
        ds.pop_back();
        if(summe(ind+1,ds,arr,s,sum,n)==true){
                return true;
        }
        return false;
}
int main(){
int arr[3]={1,2,1};
vector<int>ds;
cout<<summe(0,ds,arr,0,2,3);
return 0;
}