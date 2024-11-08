#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/** Helper function to create a linked list from a vector of integers */
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for(size_t i = 1; i < nums.size(); ++i){
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

/** Helper function to print a linked list */
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr){
        cout << current->val;
        if(current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

/** The Solution class with the deleteDuplicates function */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory of the removed node
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Empty list
    vector<int> nums1 = {};
    ListNode* head1 = createLinkedList(nums1);
    head1 = solution.deleteDuplicates(head1);
    cout << "Test Case 1: ";
    printLinkedList(head1); // Expected Output: (empty line)

    // Test Case 2: List with no duplicates
    vector<int> nums2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createLinkedList(nums2);
    head2 = solution.deleteDuplicates(head2);
    cout << "Test Case 2: ";
    printLinkedList(head2); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    // Test Case 3: List with consecutive duplicates
    vector<int> nums3 = {1, 1, 2, 3, 3};
    ListNode* head3 = createLinkedList(nums3);
    head3 = solution.deleteDuplicates(head3);
    cout << "Test Case 3: ";
    printLinkedList(head3); // Expected Output: 1 -> 2 -> 3

    // Test Case 4: All elements are duplicates
    vector<int> nums4 = {2, 2, 2, 2, 2};
    ListNode* head4 = createLinkedList(nums4);
    head4 = solution.deleteDuplicates(head4);
    cout << "Test Case 4: ";
    printLinkedList(head4); // Expected Output: 2

    // Test Case 5: Large list with random duplicates
    vector<int> nums5 = {1, 1, 1, 2, 3, 3, 4, 4, 5, 5, 5};
    ListNode* head5 = createLinkedList(nums5);
    head5 = solution.deleteDuplicates(head5);
    cout << "Test Case 5: ";
    printLinkedList(head5); // Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    // Free the allocated memory (optional, but good practice)
    // Implement a function to delete the linked list nodes if needed

    return 0;
}