vector<int> superiorElements(vector<int>&arr) {
    // Write your code here.
    vector<int>ans;
    // int n=arr.size();
    // int i,j;
    // for(i=0;i<n;i++){
    //     bool flag=true;
    //     for(j=i+1;j<n;j++){
    //         if(arr[j]>arr[i]){
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag==true){
    //         ans.push_back(arr[i]);
    //     }
    // }
    // return ans;
    int n=arr.size();
    int i;
    int maxi=INT_MIN;
    for(i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    // if required then sort thr ans else not required
    return ans;
}
//TC O(N) SC O(N)
