#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove elements with a given value from the linked list
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    // Loop through each node
    while (curr != NULL) {
        if (curr->val == val) {
            if (curr == head) {
                head = curr->next;  // Move head if it's the node to remove
            } else {
                prev->next = curr->next;  // Bypass the node to delete it
            }
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);  // Free the memory of the removed node
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* values, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(values[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeLinkedList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example usage
    int values[] = {1, 2, 6, 3, 4, 5, 6};
    int size = sizeof(values) / sizeof(values[0]);

    struct ListNode* head = createLinkedList(values, size);

    printf("Original list:\n");
    printLinkedList(head);

    // Remove elements with value 6
    head = removeElements(head, 6);

    printf("List after removing elements with value 6:\n");
    printLinkedList(head);

    // Free the list
    freeLinkedList(head);

    return 0;
}
