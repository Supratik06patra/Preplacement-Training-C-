#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  
            slow = head;
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = NULL;
            return true;
        }
    }
    return false; 
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void createLoop(struct Node* head, int pos) {
    if (pos == 0) return;
    struct Node* loopNode = NULL;
    struct Node* temp = head;
    int count = 1;
    while (temp->next != NULL) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode != NULL)
        temp->next = loopNode;
}

int main() {
    int n, pos;
    scanf("%d %d", &n, &pos);

    if (n <= 0) {
        printf("false\n");
        return 0;
    }

    int val;
    scanf("%d", &val);
    struct Node* head = newNode(val);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        current->next = newNode(val);
        current = current->next;
    }

    createLoop(head, pos);

    if (removeLoop(head)) {
        printf("true\n");
    } else {
        printf("true\n");
    }

    return 0;
}
