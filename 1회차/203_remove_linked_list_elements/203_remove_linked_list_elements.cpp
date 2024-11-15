#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;



    ListNode() : val(0), next(nullptr) {} // default constructor
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        

        if(!head){
            return nullptr;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;


        while(curr){
            
            //find and delete
            if (curr->val == val){
                if (curr == head){
                    head = curr->next;
                }

                else{
                    prev->next = curr->next;
                }
            }
            else{
                prev = curr;
            }

            curr = curr->next;
        }
        return head;
    }
    
};


ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}



void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}



int main() {
    // Example test case: Initial values [1, 2, 6, 3, 4, 5, 6], remove value 6
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    // Removing elements with value 6
    Solution solution;
    head = solution.removeElements(head, 6);

    cout << "List after removing elements with value 6: ";
    printLinkedList(head);

    return 0;
}