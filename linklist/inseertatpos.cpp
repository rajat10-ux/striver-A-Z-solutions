 

Node * insert(Node * head, int n, int pos, int val) {

 Node* newnode=new Node(val);
    if(pos==0){

        newnode->next=head;

        head=newnode;

        return head;

    }
    Node* curr=head;
    Node* prev=NULL;
    while(pos>0 && curr){

        prev=curr;

        curr=curr->next;

        pos--;

    }

    prev->next=newnode;

    newnode->next=curr;

    return head;

}

