Node*deletekk(Node*head,int k){
        if(head==NULL) return head;
   int len=counter(head);
        if(k==1){
            Node*temp=head;
        head=head->next;
        free(temp);
        return head;
        }
        int c=0;
        Node*prev=NULL;
        Node*temp=head;
        while (temp!=NULL)
        {
                c++;
                if(c==k){
                        prev->next=prev->next->next;
                        free(temp);
                        break;
                }
                prev=temp;
                temp=temp->next;
        }
        return head;
}
