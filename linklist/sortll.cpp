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
Node*soerting(Node*head1,Node*head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        head1->next=soerting(head1->next,head2);
        return head1;
    }
    else{
 head2->next=soerting(head1,head2->next);
        return head2;
    }
}
Node* sortList(Node* head){
 if(head == NULL || head ->next == NULL)
        return head;
        Node *temp = NULL;
      Node *slow = head;
      Node *fast = head;
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          
            fast = fast ->next ->next;           
        }   
        temp -> next = NULL;           
        
       Node* l1 = sortList(head);   
        Node* l2 = sortList(slow);    
        
        return soerting(l1, l2); 
}
