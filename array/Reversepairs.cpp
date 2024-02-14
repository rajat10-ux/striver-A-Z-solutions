void mergesort(vector<int>&arr,int low,int mid,int high){
    vector<int>ans;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        ans.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=ans[i-low];
    }
}
int cheker(vector<int>&arr,int low,int mid,int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right])right++;
        count+=(right-(mid+1));
    }
    return count;
}
int  merge(vector<int>&arr,int low,int high){
    int count=0;
    if(low>=high) return count;
    int mid=(low+high)/2;
    count+=merge(arr,low,mid);
    count+=merge(arr,mid+1,high);
    count+=cheker(arr,low,mid,high);
    mergesort(arr,low,mid,high);
    return count;
}
int team(vector <int> & skill, int n)
{
     return merge(skill,0,n-1);
}
// TC O(NLOGN) SC O(N)
