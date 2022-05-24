// 2022.05.24
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
    int val;
    bool preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        if(root->val != val) {
            return false;
        }
        return preorderTraversal(root->left) && preorderTraversal(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return preorderTraversal(root);
    }
};