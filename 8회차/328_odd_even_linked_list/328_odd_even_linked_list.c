#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* struct라는 글자를 그만 쓰고 싶다면..

struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

라고 정의해버리기 ~! */

struct ListNode* oddEvenList(struct ListNode* head) {
    // 노드가 0, 1, 2개인 경우, 그대로 반환
    if (!head || !head->next || !head->next->next) {
        return head;
    }
    
    struct ListNode* oddTail = head;
    struct ListNode* evenHead = head->next;
    struct ListNode* tail = head->next;

    // 3번째 노드부터 시작
    int idx = 3;
    struct ListNode* curr = head->next->next;
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
    oddTail->next = evenHead; tail->next = NULL;
    return head;
}


/////////////////////// 테스트용 함수 ///////////////////////

// 연결 리스트를 생성하는 함수
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }

    return head;
}

// 연결 리스트를 출력하는 함수
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// 메인 함수
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 입력 리스트 생성
    struct ListNode* head = createList(arr, size);

    printf("Original List:\n");
    printList(head);

    // oddEvenList 함수 호출
    struct ListNode* result = oddEvenList(head);

    printf("Modified List:\n");
    printList(result);

    return 0;
}