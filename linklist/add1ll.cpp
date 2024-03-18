Node* reversell(Node* head) {
        Node*forward=NULL;
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
 }
 Node* addTwoNumbers(Node* l1, Node* l2) {
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        Node*t1=l1;
        Node*t2=l2;
        int carry=0;
        while(t1!=NULL || t2!=NULL){
            int sum=carry;
            if(t1) sum+=t1->data;
            if(t2) sum+=t2->data;
            Node*newNode=new Node(sum%10);
            carry=sum/10;
            temp->next=newNode;
            temp=temp->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry){
            Node*newNode=new Node(carry);
            temp->next=newNode;
        }
        return dummy->next;
    }
Node *addOne(Node *head)
{
    // Write Your Code Here.temp,
    Node*temp=head;
    temp=reversell(temp);
    Node*one=new Node(1);
    Node*ans=addTwoNumbers(temp,one);
    ans=reversell(ans);
    return ans;
}
