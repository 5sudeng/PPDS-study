#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode sentinel;
    sentinel.next = NULL;  // Initialize the sentinel node's next pointer
    struct ListNode* curNode = &sentinel;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            curNode->next = list1;
            list1 = list1->next;
        } else {
            curNode->next = list2;
            list2 = list2->next;
        }
        curNode = curNode->next;
    }

    curNode->next = list1 ? list1 : list2;
    return sentinel.next;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

// Helper function to free the linked list
void freeList(struct ListNode* node) {
    while (node != NULL) {
        struct ListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    // Creating first sorted list: 1 -> 2 -> 4
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // Creating second sorted list: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    // Merging the two lists
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    // Printing the merged list
    printf("Merged List: ");
    printList(mergedList);

    // Free the memory used by the lists
    freeList(mergedList);

    return 0;
}
