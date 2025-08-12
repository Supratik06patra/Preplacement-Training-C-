#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

    struct Node* curr = head;

    if (x == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(curr);
        return head;
    }

    for (int i = 1; i < x && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL)
        return head;

    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    free(curr);
    return head;
}
