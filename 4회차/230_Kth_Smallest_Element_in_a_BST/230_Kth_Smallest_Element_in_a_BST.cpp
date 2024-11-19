/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int count;
    int result;

public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        result = 0;
        inorderHelp(root, k);
        return result;
    }

    void inorderHelp(TreeNode* curNode, int k){
        if (curNode != nullptr){
            inorderHelp(curNode->left, k);

            count ++;
            if (count == k){
                result = curNode->val;
            }

            inorderHelp(curNode->right, k);
        }
    }
};