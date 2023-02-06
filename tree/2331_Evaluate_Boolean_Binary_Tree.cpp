// 2023.02.06
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
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val == 2) {
            return left || right;
        }
        return left && right;
    }
};