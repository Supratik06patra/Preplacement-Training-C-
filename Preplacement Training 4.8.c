struct Node* pairWiseSwap(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* new_head = head->next; 
    while (curr != NULL && curr->next != NULL) {
        struct Node* first = curr;
        struct Node* second = curr->next;
        struct Node* next_pair = second->next;

        second->next = first;
        first->next = next_pair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = first;
        curr = next_pair;
    }

    return new_head;
}