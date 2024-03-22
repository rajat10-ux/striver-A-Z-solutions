Node* mergelist(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    if (head1->data < head2->data) {
        head1->child = mergelist(head1->child, head2);
        return head1;
    } else {
        head2->child = mergelist(head1, head2->child);
        return head2;
    }
}
Node* flattenLinkedList(Node* head) {
    if (head==NULL){
		return NULL;
	}
    Node*ans=mergelist(head,flattenLinkedList(head->next));
	return ans;
}
