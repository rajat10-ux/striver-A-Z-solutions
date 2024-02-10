string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(),book.end());
    int i=0,j=n-1;
    while(i<j){
        int sum=book[i]+book[j];
        if(sum==target){
            return "YES";
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return "NO";
}
// TC O(nlogn+n)
//SC O(1)
//2.approach
   vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[nums[i]]=i;
        }
return {-1,-1};
  }
// TC O(nums.size());
//SC O(n)


