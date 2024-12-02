/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 노드가 0, 1, 2개인 경우, 그대로 반환
        if (!head || !head->next || !head->next->next) {
            return head;
        }

        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode* tail = head->next;

        int idx = 3;
        ListNode* curr = head->next->next;
        while (curr) {
            if (idx%2==1) {
                oddTail->next = curr;
                oddTail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
            curr = curr->next; idx++;
        }
        oddTail->next = evenHead; tail->next = nullptr;
        return head;
    }
};