// 2022.10.17
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
    int res = 0;
    void dfs(TreeNode* cur, int maxVal) {
        if(cur->val >= maxVal) {
            res++;
        }
        if(cur->left) {
            dfs(cur->left, max(maxVal, cur->val));
        }
        if(cur->right) {
            dfs(cur->right, max(maxVal, cur->val));
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root, -(1e4 + 7)); // dfs(root, root->val);
        return res;
    }
};