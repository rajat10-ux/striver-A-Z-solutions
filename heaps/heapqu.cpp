#include<bits/stdc++.h>
using namespace std;
int smallest(int*arr,int n,int k){
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
                pq.push(arr[i]);
        }
        for(int i=k;i<n;i++){
                if(arr[i]<pq.top()){
                        pq.pop();
                        pq.push(arr[i]);
                }
        }
        return pq.top();
}
int largest(int*arr,int n,int k){       priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
                pq.push(arr[i]);
        }
        for(int i=k;i<n;i++){
                if(arr[i]>pq.top()){
                        pq.pop();
                        pq.push(arr[i]);
                }
        }
        return pq.top();
}
int main(){
int arr[7]={3,5,4,6,9,8,7};
cout<<smallest(arr,7,1);
cout<<largest(arr,7,1)<<endl;
return 0;
}