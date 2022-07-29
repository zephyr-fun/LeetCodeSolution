// 2022.07.29
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
    map<int, map<int, vector<int>>> map; // col, row
    void dfs(TreeNode* root, int row, int col) {
        if(root == nullptr) {
            return ;
        }
        map[col][row].emplace_back(root->val);
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(auto [ck, cv] : map) {
            vector<int> temp;
            for(auto [rk, rv] : cv) {
                sort(rv.begin(), rv.end());
                for(auto it : rv) {
                    temp.emplace_back(it);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};