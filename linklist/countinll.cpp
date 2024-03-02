int length(Node *head)
{
	int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
//TC O(N)
