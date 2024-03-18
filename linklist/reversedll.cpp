Node* reverseDLL(Node* head)
{   
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*temp=head;
    Node*last=NULL;
    while(temp!=NULL){
        last=temp->prev;
        temp->prev=temp->next;
        temp->next=last;
        temp=temp->prev;
    }
    return last->prev;
}
