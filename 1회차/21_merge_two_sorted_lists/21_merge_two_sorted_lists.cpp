#include <iostream>
#include <vector>

/* 
2개의 sorted linked list(non-decreasing order)가 존재할 때, 두 list를 merge하는 문제
linked list의 head를 return 해야 함

ex. 
list1 : [1, 2, 4]
list2 : [1, 3, 4]
output : [1, 1, 2, 3, 4, 4]
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel;
        ListNode* curNode = &sentinel;

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

        // Append the remaining nodes
        curNode->next = list1 ? list1 : list2;

        return sentinel.next;
    }
};

// Helper function to print the list
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    // Example lists to merge
    std::vector<int> list1_values = {1, 2, 4};
    std::vector<int> list2_values = {1, 3, 4};

    // Create the linked lists
    ListNode* list1 = createList(list1_values);
    ListNode* list2 = createList(list2_values);

    // Merge the lists
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    return 0;
}
