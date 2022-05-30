// 2022.05.30
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
    int sum = 0;
    void traversal(TreeNode* root, int cur) {
        if(root->left == nullptr && root->right == nullptr) {
            cur = cur << 1;
            cur += root->val;
            sum += cur;
        }
        if(root->left != nullptr) {
            traversal(root->left, (cur << 1) + root->val);
        }
        if(root->right != nullptr) {
            traversal(root->right, (cur << 1) + root->val);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        traversal(root, 0);
        return sum;
    }
};