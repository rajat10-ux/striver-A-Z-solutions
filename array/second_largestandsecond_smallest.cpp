#include<bits/stdc++.h>
int secondlargestnumber(vector<int>&arr,int n){
    if(n<2) return -1;
    int maxi=INT_MIN,secondmaxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            secondmaxi=maxi;
            maxi=arr[i];
        }
        else if(arr[i]>secondmaxi && arr[i]!=maxi){
            secondmaxi=arr[i];
        }
    }
    return secondmaxi;
}
int secondsmallestnumber(vector<int>&arr,int n){
    if(n<2) return -1;
    int maxi=INT_MAX,secondmaxi=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<maxi){
            secondmaxi=maxi;
            maxi=arr[i];
        }
        else if(arr[i]<secondmaxi && arr[i]!=maxi){
            secondmaxi=arr[i];
        }
    }
    return secondmaxi;
}
vector<int> getSecondOrderElements(int n, vector<int> arr) {
    // Write your code here.
    int a=secondlargestnumber(arr,n);
    int b=secondsmallestnumber(arr,n);
    return {a,b};
}
//TC O(N)
//SC O(~~~~nearly equal to 1)
