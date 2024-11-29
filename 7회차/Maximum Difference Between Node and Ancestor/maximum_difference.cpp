#include <iostream>
using namespace std;

// TreeNode 구조체 정의
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// min 함수 정의
template <typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}

// max 함수 정의
template <typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        // DFS 함수 정의
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int currMin, int currMax) {
        if (!node) {
            // 리프 노드에 도달한 경우 최대 차이를 반환
            return currMax - currMin;
        }

        // 현재 노드 값으로 최소값과 최대값 업데이트
        currMin = Min(currMin, node->val);
        currMax = Max(currMax, node->val);

        // 왼쪽과 오른쪽 서브트리를 탐색
        int leftDiff = dfs(node->left, currMin, currMax);
        int rightDiff = dfs(node->right, currMin, currMax);

        // 왼쪽과 오른쪽 서브트리 중 더 큰 차이를 반환
        return Max(leftDiff, rightDiff);
    }
};

// 테스트 실행
int main() {
    // 트리 생성
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);

    // 솔루션 실행
    Solution solution;
    cout << solution.maxAncestorDiff(root) << endl; // 출력: 7

    // 메모리 해제
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
