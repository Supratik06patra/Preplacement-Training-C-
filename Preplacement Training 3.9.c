#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* addTwoLists(struct Node* head1, struct Node* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);

    int carry = 0;
    struct Node* dummy = newNode(0);
    struct Node* curr = dummy;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int val1 = (head1 != NULL) ? head1->data : 0;
        int val2 = (head2 != NULL) ? head2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        curr->next = newNode(sum % 10);
        curr = curr->next;

        if (head1 != NULL) head1 = head1->next;
        if (head2 != NULL) head2 = head2->next;
    }

    struct Node* result = reverse(dummy->next);
    free(dummy);
    return result;
}
