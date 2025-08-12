#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}
