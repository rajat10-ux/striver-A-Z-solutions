long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi=INT_MIN;
    long long  sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
        maxi=max(maxi,sum);
    }
    return maxi;
}
//TC O(N) 
