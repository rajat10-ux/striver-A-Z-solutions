bool hasCycle(ListNode *head) {
        // unordered_map<ListNode*,int>mp;
        // ListNode*temp=head;
        // while(temp!=NULL){
        //     // mp[temp]=1;
        //     if(mp.find(temp)!=mp.end()){
        //         return true;
        //     }
        //     mp[temp]=1;
        //     temp=temp->next;
        // }
        // return false;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
}
