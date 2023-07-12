#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} listint_t;

listint_t* createNode(int number) {
    listint_t* newNode = (listint_t*)malloc(sizeof(listint_t));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = number;
    newNode->next = NULL;
    return newNode;
}

listint_t* insert_node(listint_t** head, int number) {
    listint_t* newNode = createNode(number);
    if (newNode == NULL) {
        return NULL;
    }

    listint_t* prev = NULL;

    while (current != NULL && current->data < number) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }

    return newNode;
}

void printList(listint_t* head) {
    listint_t* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(listint_t* head) {
    listint_t* current = head;
    listint_t* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    listint_t* head = NULL;
    insert_node(&head, 4);
    insert_node(&head, 2);
    insert_node(&head, 6);
    insert_node(&head, 5);
    insert_node(&head, 1);

    printList(head);

    freeList(head);

    return 0;
}
