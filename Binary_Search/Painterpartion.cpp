#include<bits/stdc++.h>
int helper(vector<int>&arr,int d){
    int student=1,pgcount=0;
    for(int i=0;i<arr.size();i++){
        if(pgcount+arr[i]<=d){
            pgcount+=arr[i];
        }
        else{
            student+=1;
            pgcount=arr[i];
        }
    }
    return student;
}
int findpage(vector<int>&arr,int n,int m){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(helper(arr,mid)<=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    return findpage(boards,boards.size(),k);
}
