   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        cin.tie(NULL);
       vector<int>ans;
       deque<int>dq;
       for(int i=0;i<k;i++){
         int el=nums[i];
         while(!dq.empty() && el>nums[dq.back()]){
            dq.pop_back();
         }
         dq.push_back(i);
       }
       for(int i=k;i<nums.size();i++){
         ans.push_back(nums[dq.front()]);
         if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
         }
         while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
         }
         dq.push_back(i);
       }
       ans.push_back(nums[dq.front()]);
       return ans;
    }
