int upper(vector<int>&arr,int x,int m){
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int helper(vector<vector<int>>&arr,int x,int m, int n){
    int count=0;
    for(int i=0;i<n;i++){
        count+=upper(arr[i],x,m);
    }
    return count;
}
    int median(vector<vector<int>>&arr, int m, int n){
        int mini=INT_MAX,maxi=INT_MIN;
        n=arr.size(),m=arr[0].size();
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i][0]);
            maxi=max(maxi,arr[i][m-1]);
        }
        int req=(m*n)/2;
        int low=mini,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int help=helper(arr,mid,m,n);
            if(help<=(n*m)/2){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
// tc O(log(10^9)*n*log(m))
