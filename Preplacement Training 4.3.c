struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct DLLNode* reverseDLL(struct DLLNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct DLLNode* curr = head;
    struct DLLNode* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}
