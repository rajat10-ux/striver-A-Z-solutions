int getlength(Node*slow,Node*fast){
    int count=1;
    fast=fast->next;
    while(slow!=fast){
count++;
fast=fast->next;
    }
    return count;
}
int lengthOfLoop(Node *head) {
    Node*slow=head;
    Node*fast=head;
    int ans=0;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
     return getlength(slow,fast);
        }
    }
    return 0;
}
