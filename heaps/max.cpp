#include<bits/stdc++.h>
using namespace std;
int getksmall(int *arr,int n,int k){
 priority_queue<int>pq;
 for (int i = 0; i < k; i++)
 {
        pq.push(arr[i]);
 }
 for (int  i = k; i < n; i++)
 {
        int element=arr[i];
        if(pq.top()>element){
                pq.pop();
                pq.push(element);
        }
 }
 return pq.top();
}
int getklarge(int *arr,int n,int k){
 priority_queue<int,vector<int>,greater<int>>pq;
 for (int i = 0; i < k; i++)
 {
        pq.push(arr[i]);
 }
 for (int  i = k; i < n; i++)
 {
        int element=arr[i];
        if(pq.top()<element){
                pq.pop();
                pq.push(element);
        }
 }
 return pq.top();
}
int main(){
int arr[7]={3,4,5,6,9,8,7};
cout<<getksmall(arr,7,7)<<endl;
cout<<getklarge(arr,7,7);
return 0;
}