 long long mergesort(long long arr[],long long low,long long mid,long long high){
        vector<long long>ans;
        long long  left=low;
        long long right=mid+1;
        long long  cnt=0,i;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                ans.push_back(arr[left]);
                left++;
            }
            else{
                ans.push_back(arr[right]);
                cnt+=mid-left+1;
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
        for(i=low;i<=high;i++){
            arr[i]=ans[i-low];
        }
        return cnt;
    }
  
  long long int merge(long long arr[],long long low,long long high){
      long long cnt=0;
      if(low>=high) return cnt;
      long long mid=low+(high-low)/2;
      cnt+=merge(arr,low,mid);
      cnt+=merge(arr,mid+1,high);
      cnt+=mergesort(arr,low,mid,high);
      return cnt;
  }
    long long int inversionCount(long long arr[], long long N)
    {
       long long t=merge(arr,0,N-1);
       return t;
    }

// TC (NLOGN) SC O(N)
