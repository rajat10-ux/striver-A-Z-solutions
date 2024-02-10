bool check(vector<int>& nums) {
    int count=0;
for(int i=0;i<nums.size();i++){
// if(nums[i+1]==nums[i])continue;
if(nums[i]>nums[(i+1)%nums.size()]){
count++;
}
}
if(count>1){
return false;
}
return true;   
}
//TC OF SOLUTION IS O(nums.size()) 
//SC IS O(1)
