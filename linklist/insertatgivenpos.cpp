Node*insertpositionval(Node*head,int el,int val){
        if(head==NULL){
                return NULL;
        }
        if(head->data==val){
          Node*temp=new Node(el);
        temp->next=head;
        head=temp;
        }
        Node*temp=head;
        while (temp!=NULL)
        {
                if(temp->next->data==val){
                        Node*xl=new Node(el);
                        xl->next=temp->next;
                        temp->next=xl;
                        break;
                }
                temp=temp->next;
        }
        return head;
}
