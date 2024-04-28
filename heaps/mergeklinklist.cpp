 class compare{
     public:
     bool operator()(ListNode*a,ListNode*b){
         return a->val>b->val;
     }
 };
// function to merge k link list 
 ListNode* mergeKLists(vector<ListNode*>& lists) {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++){
            ListNode*listHead=lists[i];
            if(listHead!=NULL){
                 pq.push(listHead);
            }
        }
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(!pq.empty()){
            ListNode*topelement=pq.top();
            pq.pop();
            if(head==NULL){
                head=topelement;
                tail=topelement;
                if(tail->next!=NULL){
                    pq.push(tail->next);
                }
            }
            else{
                tail->next=topelement;
                tail=topelement;
                if(tail->next!=NULL){
                     pq.push(tail->next);
                }
            }
        }
        return head;
    }
