Node*insertathead(Node*head,int val){
        Node*temp=new Node(val);
        temp->next=head;
        head=temp;
        return temp;
}
Node*insertattail(Node*head,int val){
         if(head==NULL ){
                return new Node(val);
        }
Node*temp=head;
while (temp->next!=NULL)
{
        temp=temp->next;
}
Node*newnode=new Node(val);
temp->next=newnode;
return head;
}
