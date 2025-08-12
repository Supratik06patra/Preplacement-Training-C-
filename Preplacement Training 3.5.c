#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getKthFromLast(struct Node* head, int k) {
    struct Node* fast = head;
    struct Node* slow = head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            return -1;  
        }
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow ? slow->data : -1;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); 

    if (n <= 0) {
        printf("-1\n");
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

    int result = getKthFromLast(head, k);
    printf("%d\n", result);

    return 0;
}
