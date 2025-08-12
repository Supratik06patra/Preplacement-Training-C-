#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool searchKey(int n, struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, key;
    scanf("%d %d", &n, &key);  

    if (n <= 0) return 0;

    int val;
    scanf("%d", &val);
    struct Node* head = newNode(val);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        current->next = newNode(val);
        current = current->next;
    }

    if (searchKey(n, head, key)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
