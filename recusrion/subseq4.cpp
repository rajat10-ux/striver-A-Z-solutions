#include<bits/stdc++.h>
using namespace std;
int summe(int ind,int*arr,int s,int sum,int n){
        if(s>sum)return 0;
        if(ind==n){
                if(s==sum){
                             return 1;
                        cout<<endl;
                }
                return 0;
        }
     //   ds.push_back(arr[ind]);
        s+=arr[ind];
       int l=summe(ind+1,arr,s,sum,n);
        s-=arr[ind];
        // ds.pop_back();
        int r=summe(ind+1,arr,s,sum,n);
        return l+r;
}
int main(){
int arr[]={1,2,3,6,9,6,2,7};
// vector<int>ds;
cout<<summe(0,arr,0,9,8);
return 0;
}