Node*deleteel(Node*head,int el){
        if(head==NULL) return head;
        if(head->data==el){
            Node*temp=head;
        head=head->next;
        free(temp);
        return head;
        }
        Node*prev=NULL;
        Node*temp=head;
        while (temp!=NULL)
        {
                if(temp->data==el){
                        prev->next=prev->next->next;
                        free(temp);
                        break;
                }
                prev=temp;
                temp=temp->next;
        }
        return head;
}
