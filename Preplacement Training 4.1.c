#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* sortedInsert(struct Node* head, int x) {
    struct Node* newNode = createNode(x);
    if (head == NULL)
        return newNode;

    if (x < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node* curr = head;

    while (curr->next != NULL && curr->data < x)
        curr = curr->next;

    if (x <= curr->data) {
        struct Node* prevNode = curr->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = curr;
        curr->prev = newNode;
    } else {
        curr->next = newNode;
        newNode->prev = curr;
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

struct Node* createDLL(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* curr = head;

    for (int i = 1; i < n; ++i) {
        struct Node* temp = createNode(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

int main() {
    int arr[] = {3, 5, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;

    struct Node* head = createDLL(arr, n);

    printf("Original list: ");
    printList(head);

    head = sortedInsert(head, x);

    printf("After inserting %d: ", x);
    printList(head);

    return 0;
}
