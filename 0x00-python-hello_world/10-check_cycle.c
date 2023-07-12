#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} listint_t;

int check_cycle(listint_t* list) {
    listint_t* slow = list;
    listint_t* fast = list;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;  / Cycle detected
        }
    }

    return 0;  // No cycle found
}

int main() {
    // Create a sample linked list with a cycle
    listint_t* head = (listint_t*)malloc(sizeof(listint_t));
    listint_t* node1 = (listint_t*)malloc(sizeof(listint_t));
    listint_t* node2 = (listint_t*)malloc(sizeof(listint_t));
    listint_t* node3 = (listint_t*)malloc(sizeof(listint_t));

    head->data = 1;
    node1->data = 2;
    node2->data = 3;
    node3->data = 4;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;  // Creating a cycle

    // Call the check_cycle function
    Cycle = check_cycle(head);

    // Print the result
    printf("Cycle detected: %s\n", hasCycle ? "Yes" : "No");

    // Free the memory
    free(head);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
