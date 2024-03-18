/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    
// if(head==NULL || head->next==NULL){
//     return head;
// }
// Node*temp=head;
// Node*zeroHead=new Node(-1);
// Node*oneHead=new Node(-1);
// Node*twoHead=new Node(-1);
// Node*zero=zeroHead;
// Node*one=oneHead;
// Node*two=twoHead;
// while(temp!=NULL){
//     if(temp->data==0){
//         zero->next=temp;
//         zero=zero->next;
//     }
//     else if(temp->data==1){
//         one->next=temp;
//         one=one->next;
//     }
//     else if(temp->data==2){
//         two->next=temp;
//         two=two->next;
//     }
//     temp=temp->next;
// }
// zero->next=one->next?one->next:two->next;
// one->next=two->next;
// two->next=NULL;
// head=zero->next;
// delete(zeroHead);
// delete(oneHead);
// delete(twoHead);
// return head;
if (!head || !(head->next)) 
        return head; 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
    Node *zero = zeroD, *one = oneD, *two = twoD; 
    Node* curr = head; 
    while (curr) { 
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
        } 
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
        } 
        curr = curr->next; 
    } 
  
  
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 

    head = zeroD->next; 
  
  
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head; 
}
