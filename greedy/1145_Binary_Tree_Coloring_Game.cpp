// 2023.02.03
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int lsz;
        int rsz;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if(node == nullptr) {
                return 0;
            }
            int ls = dfs(node->left);
            int rs = dfs(node->right);
            if(node->val == x) {
                lsz = ls;
                rsz = rs;
            }
            return ls + rs + 1;
        };
        dfs(root);
        return max({lsz, rsz, n - 1 - lsz - rsz}) * 2 > n;
    }
};