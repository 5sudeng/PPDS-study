#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
struct ListNode {
    int val;
    struct ListNode* next;
};

// 중간 노드 찾기 함수
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // fast가 끝에 도달할 때까지 반복
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // slow 포인터가 중간 노드를 가리킴
    return slow;
}

// 새로운 노드를 생성하는 함수
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 리스트 출력 함수 (중간 노드부터 끝까지)
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // 연결 리스트 생성 예시: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    struct ListNode* middle = middleNode(head);

    // 중간 노드부터 출력
    printList(middle);  // 예상 출력: 3 4 5

    // 메모리 해제
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
