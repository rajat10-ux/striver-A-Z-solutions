  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push(make_pair(nums[i],i));
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
            while(pq.top().second<=i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
