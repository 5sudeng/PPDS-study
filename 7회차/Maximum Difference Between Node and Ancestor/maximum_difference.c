#include <stdio.h>
#include <stdlib.h>

// TreeNode 구조체 정의
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// TreeNode 생성 함수
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// min 함수 정의
int min(int a, int b) {
    return (a < b) ? a : b;
}

// max 함수 정의
int max(int a, int b) {
    return (a > b) ? a : b;
}

// DFS 함수 정의
int dfs(TreeNode* node, int currMin, int currMax) {
    if (!node) {
        // 리프 노드에 도달한 경우 최대 차이를 반환
        return currMax - currMin;
    }

    // 현재 노드 값으로 최소값과 최대값 업데이트
    currMin = min(currMin, node->val);
    currMax = max(currMax, node->val);

    // 왼쪽과 오른쪽 서브트리를 탐색
    int leftDiff = dfs(node->left, currMin, currMax);
    int rightDiff = dfs(node->right, currMin, currMax);

    // 왼쪽과 오른쪽 서브트리 중 더 큰 차이를 반환
    return max(leftDiff, rightDiff);
}

// maxAncestorDiff 함수 정의
int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
}

// 트리 메모리 해제 함수
void freeTree(TreeNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

