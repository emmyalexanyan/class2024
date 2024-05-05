DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* temp = nullptr;
    DoublyLinkedListNode* newHead = nullptr;

   while (current != nullptr) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    newHead = llist;
    while (newHead != nullptr && newHead->prev != nullptr) {
        newHead = newHead->prev;
    }

    return newHead; 
    
}
