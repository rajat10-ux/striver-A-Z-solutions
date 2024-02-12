int longestSuccessiveElements(vector<int>&arr) {
    if(arr.size()==0) return 0;
    sort(arr.begin(),arr.end());
    int count=0,maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i-1]==arr[i])continue;
        if(arr[i]==arr[i-1]+1){
            count++;
        }   
        else{
            count=1;
        }
        maxi=max(maxi,count);
    }
    return maxi;
}
// TC O(NLONN+N) SC O(1);
