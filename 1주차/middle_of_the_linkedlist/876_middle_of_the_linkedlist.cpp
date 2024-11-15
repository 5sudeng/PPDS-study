#include <iostream>
using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cur=head;
        int cnt=0;
        while (cur){
            cnt+=1;
            cur=cur->next;
        }
        for(int i=0;i<cnt/2;++i){
            head=head->next;
        }
        return head;
        
    }
    ListNode* middleNode2(ListNode* head) {
    //투포인터
        ListNode* slow = head;
        ListNode* fast = head;
        
        // fast가 끝에 도달할 때까지 반복
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow 포인터가 중간 노드를 가리킴
        return slow;
    }
};

// 테스트를 위한 간단한 함수들
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // 연결 리스트 생성 예시: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    // 중간 노드부터 출력
    printList(middle);  // 예상 출력: 3 4 5

    return 0;
}
