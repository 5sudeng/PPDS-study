#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Function to create a new node */
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/* Function to create a linked list from an array */
struct ListNode* createLinkedList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

/* Function to print the linked list */
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

/* Function to free the linked list */
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

/* Function to delete duplicates */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found; remove the next node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free memory of the removed node
        } else {
            // Move to the next distinct element
            current = current->next;
        }
    }
    return head;
}

int main() {
    // Test Case 1: Empty list
    int nums1[] = {};
    struct ListNode* head1 = createLinkedList(nums1, 0);
    head1 = deleteDuplicates(head1);
    printf("Test Case 1: ");
    printLinkedList(head1); // Expected Output: (empty line)
    freeLinkedList(head1);

    // Test Case 2: List with no duplicates
    int nums2[] = {1, 2, 3, 4, 5};
    struct ListNode* head2 = createLinkedList(nums2, 5);
    head2 = deleteDuplicates(head2);
    printf("Test Case 2: ");
    printLinkedList(head2); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5
    freeLinkedList(head2);

    // Test Case 3: List with consecutive duplicates
    int nums3[] = {1, 1, 2, 3, 3};
    struct ListNode* head3 = createLinkedList(nums3, 5);
    head3 = deleteDuplicates(head3);
    printf("Test Case 3: ");
    printLinkedList(head3); // Expected Output: 1 -> 2 -> 3
    freeLinkedList(head3);

    // Test Case 4: All elements are duplicates
    int nums4[] = {2, 2, 2, 2, 2};
    struct ListNode* head4 = createLinkedList(nums4, 5);
    head4 = deleteDuplicates(head4);
    printf("Test Case 4: ");
    printLinkedList(head4); // Expected Output: 2
    freeLinkedList(head4);

    // Test Case 5: Large list with random duplicates
    int nums5[] = {1, 1, 1, 2, 3, 3, 4, 4, 5, 5, 5};
    struct ListNode* head5 = createLinkedList(nums5, 11);
    head5 = deleteDuplicates(head5);
    printf("Test Case 5: ");
    printLinkedList(head5); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5
    freeLinkedList(head5);

    return 0;
}