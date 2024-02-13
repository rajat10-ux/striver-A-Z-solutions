int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    map<int,int>mp;
    mp[0]=1;
    int count=0,n=arr.size();
    int sum=0,prefix=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int remo=sum-k;
        count+=mp[remo];
        mp[sum]+=1;
    }
    return count;
}
//TC O(N) SC O(N)
