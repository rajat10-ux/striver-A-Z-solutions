int length (ListNode* head)
    {
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode*curr=head;
       ListNode*prev=NULL;
       ListNode*forward=NULL;
       int count=0;
        int len=length(head);
        if(len<k){
            return head;
        }
       while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
       }   
       if(forward!=NULL)
       head->next=reverseKGroup(forward,k);
       return prev;
    }
