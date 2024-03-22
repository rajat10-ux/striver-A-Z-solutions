Node * removeDuplicates(Node *head)
{
 Node*temp=head;
 Node*nextNode=temp->next;
 while(temp!=NULL && temp->next!=NULL){
        while(nextNode!=NULL && nextNode->data==temp->data){
              nextNode=nextNode->next;
        }
        temp->next=nextNode;
        if(nextNode) nextNode->prev=temp;
        temp=temp->next;
 }   
 return head;
}
