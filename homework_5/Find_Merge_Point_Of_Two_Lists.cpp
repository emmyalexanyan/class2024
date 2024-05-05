int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;

    while (temp1 != temp2) {
        if (temp1 == nullptr) {
            temp1 = head2;
        } else {
            temp1 = temp1->next;
        }
        if (temp2 == nullptr) {
            temp2 = head1;
        } else {
            temp2 = temp2->next;
        }
    }
    if (temp1 != nullptr) {
        return temp1->data;
    } else {
        return -1; 
    }

}
