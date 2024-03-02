 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        ListNode*t1=l1;
        ListNode*t2=l2;
        int carry=0;
        while(t1!=NULL || t2!=NULL){
            int sum=carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
            ListNode*newNode=new ListNode(sum%10);
            carry=sum/10;
            temp->next=newNode;
            temp=temp->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry){
            ListNode*newNode=new ListNode(carry);
            temp->next=newNode;
        }
        return dummy->next;
    }
