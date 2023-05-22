// 2023.05.22
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
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/solution/jian-ji-xie-fa-diao-yong-zi-shen-pythonj-64lf/
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        limit -= root->val;
        if(root->left == nullptr && root->right == nullptr) {
            return limit > 0 ? nullptr : root;
        }
        if(root->left) {
            root->left = sufficientSubset(root->left, limit);
        }
        if(root->right) {
            root->right = sufficientSubset(root->right, limit);
        }
        return root->left || root->right ? root : nullptr;
    }
};