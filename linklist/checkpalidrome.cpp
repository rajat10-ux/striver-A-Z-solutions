
Node*reversell(Node*head){
    Node*forward=NULL;
    Node*curr=head;
    Node*prev=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
     if(head==NULL || head->next==NULL)return true;
       Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node*reverseHead=reversell(slow->next);
    Node*temp=head;
    Node*sec=reverseHead;
    while(sec!=NULL){
        if(temp->data!=sec->data){
          //  reversell(reverseHead);
            return false;
        }
        temp=temp->next;
        sec=sec->next;
    }
    //reversell(reverseHead);
    return true;
}
