Node * deleteAllOccurrences(Node* head, int k) {
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            if(temp==head){
                head=head->next;
            }
            Node*nextNode=temp->next;
            Node*prevNode=temp->prev;
            if(nextNode!=NULL) nextNode->prev=prevNode;
            if(prevNode!=NULL) prevNode->next=nextNode;
            temp=nextNode;
        }
        else{
             temp=temp->next;
        }
    }
    return head;
}
