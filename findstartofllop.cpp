Node*detect(Node*head){
    if(head==NULL  || head->next==NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node *firstNode(Node *head)
{
    //    Write your code here.
Node*intersect=detect(head);
if(intersect==NULL || intersect->next==NULL){
    return NULL;
}
Node*slow=head;
while(slow!=intersect){
    slow=slow->next;
    intersect=intersect->next;
}
return slow;
}
