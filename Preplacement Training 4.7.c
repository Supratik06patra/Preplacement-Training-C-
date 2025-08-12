int isCircular(struct Node* head) {
    if (head == NULL)
        return 1;

    struct Node* curr = head->next;

    while (curr != NULL && curr != head) {
        curr = curr->next;
    }

    if (curr == head)
        return 1;

    return 0;
}