    ListNode* reverseList(ListNode* head) {
        ListNode*forward=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
