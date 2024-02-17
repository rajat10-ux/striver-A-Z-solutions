#include<bits/stdc++.h>
int finddays(vector<int>&arr,int cap){
    int days=1,load=0;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]>cap){
            days+=1;
            load=arr[i];
        }
        else{
            load+=arr[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int>&arr, int d)
{
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(finddays(arr,mid)<=d){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
//TC O(LOG(MIN)*n)
