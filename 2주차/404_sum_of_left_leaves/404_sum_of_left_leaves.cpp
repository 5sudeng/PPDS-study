#include <iostream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    //constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        

        int ans = 0;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* curnode =q.front();
            q.pop();


            if (curnode->left !=nullptr){
                
                TreeNode* temp = curnode->left;
                if ((temp->left == nullptr) && (temp->right == nullptr)){
                    ans += temp->val;
                } 
                else{
                    q.push(curnode->left);
                }

            }

            if (curnode->right != nullptr){
                q.push(curnode ->right);
            }
        }

        return ans;
    }
};