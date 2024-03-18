Node* reverseLinkedList(Node *head)
{
//     Node*forward=NULL;
//     Node*prev=NULL;
//    Node*temp=head;
//     while(temp!=NULL){
//         forward=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=forward;
//     }
//     return prev;
if(head==NULL || head->next==NULL){
    return head;
}
Node*newhead=reverseLinkedList(head->next);
Node*front=head->next;
front->next=head;
head->next=NULL;
return newhead;
}
