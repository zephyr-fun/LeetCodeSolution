// 2022.08.22
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
    int n = 0;
    int m;
    vector<vector<string>> res;
    void findHeight(TreeNode* cur, int depth) {
        if(cur == nullptr) {
            return ;
        }
        n = max(n, depth);
        findHeight(cur->left, depth + 1);
        findHeight(cur->right, depth + 1);
    }
    void build(TreeNode* cur, int row, int col) {
        if(cur == nullptr) {
            return ;
        }
        res[row][col] = to_string(cur->val);
        int offset = 0;
        if(n - 2 - row >= 0) {
            offset = 1 << (n - 2 - row);
        }
        build(cur->left, row + 1, col - offset);
        build(cur->right, row + 1, col + offset);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        findHeight(root, 1);
        m = (1 << n) - 1;
        res.resize(n, vector<string>(m, string("")));
        build(root, 0, (m - 1) / 2);
        return res;
    }
};