#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

int is_palindrome(ListNode** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // Empty list or single element list is considered a palindrome
        return 1;
    }

    ListNode* slow = *head;
    ListNode* fast = *head;
    ListNode* prev_slow = *head;
    ListNode* mid_node = NULL;  // To handle odd-sized lists

    // Move fast pointer by two and slow pointer by one
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // If fast is not NULL, it means the list has odd size
    if (fast != NULL) {
        mid_node = slow;
        slow = slow->next;
    }

    // Reverse the second half of the list
    ListNode* second_half = slow;
    prev_slow->next = NULL;
    ListNode* prev = NULL;
    ListNode* current = second_half;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second_half = prev;

    // Compare the first half and reversed second half
    ListNode* ptr1 = *head;
    ListNode* ptr2 = second_half;
    int is_palindrome = 1;

    while (ptr2 != NULL) {
        if (ptr1->data != ptr2->data) {
            is_palindrome = 0;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Reconstruct the original list by reversing the second half back
    prev = NULL;
    current = second_half;
    next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second_half = prev;

    // If the list had odd size, reconnect the mid node
    if (mid_node != NULL) {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    } else {
        prev_slow->next = second_half;
    }

    return is_palindrome;
}

int main() {
    ListNode* head = NULL;
    ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));

    // Example linked list: 1 -> 2 -> 3 -> 2 -> 1
    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = node3;
    node3->data = 3;
    node3->next = node4;
    node4->data = 2;
    node4->next = node5;
    node5->data = 1;
    node5->next = NULL;
    head = node1;

    int result = is_palindrome(&head);
    if (result) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Freeing allocated memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}
