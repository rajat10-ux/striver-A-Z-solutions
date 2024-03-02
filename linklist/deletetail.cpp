
Node *deleteLast(Node *list){
         Node* head=list;
    Node* temp=head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    delete (temp->next);
    temp->next=NULL;
    return head;
}
