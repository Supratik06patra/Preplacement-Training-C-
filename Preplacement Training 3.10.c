void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
