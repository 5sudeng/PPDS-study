#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체 정의
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 전역 변수 (상태 관리)
int count;    // 방문한 노드 개수
int result;   // k번째 노드의 값
int found;    // k번째 노드를 찾았는지 여부

// 중위 순회 함수
void inorderHelp(struct TreeNode* curNode, int k) {
    // base case: 노드가 없거나 k번째 노드를 이미 찾았으면 종료
    if (curNode == NULL || found) {
        return;
    }

    // 왼쪽 서브트리 탐색
    inorderHelp(curNode->left, k);

    // 현재 노드 처리
    count++;
    if (count == k) {
        result = curNode->val;
        found = 1;  // k번째 노드를 찾았음을 표시
        return;
    }

    // 오른쪽 서브트리 탐색
    inorderHelp(curNode->right, k);
}

// k번째로 작은 노드 찾기 함수
int kthSmallest(struct TreeNode* root, int k) {
    // 전역 변수 초기화
    count = 0;
    result = 0;
    found = 0;

    // 중위 순회 시작
    inorderHelp(root, k);

    // 결과 반환
    return result;
}

// TreeNode를 생성하는 헬퍼 함수 (필요하면 사용)
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 테스트 예제
int main() {
    // 트리 생성
    struct TreeNode* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->right = createNode(2);

    // k번째로 작은 값 찾기
    int k = 2;
    int result = kthSmallest(root, k);

    // 결과 출력
    printf("The %d-th smallest element is %d\n", k, result);

    return 0;
}
