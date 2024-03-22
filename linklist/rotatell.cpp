Node*helper(Node*temp,int k){
     int cnt=1;
     while(temp!=NULL){
          if(cnt==k) return temp;
          cnt++;
          temp=temp->next;
     }
     return temp;
}
Node *rotate(Node *head, int k) {
     if(head==NULL || k==0) return head;
   Node*tail=head;
   int count=1;
   while(tail->next!=NULL){
        tail=tail->next;
        count++;
   }
   if(k%count==0)return head;
   k=k%count;
   tail->next=head;
   Node*findstart=helper(head,count-k);
   head=findstart->next;
   findstart->next=NULL;
    return head;
}
