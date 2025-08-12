struct Node* intersectPoint(struct Node* head1, struct Node* head2) {
    int n1 = 0, n2 = 0;
    struct Node* temp = head1;

    while (temp != NULL) {
        n1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        n2++;
        temp = temp->next;
    }

    while (n1 > n2) {
        head1 = head1->next;
        n1--;
    }

    while (n2 > n1) {
        head2 = head2->next;
        n2--;
    }

    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;  
}