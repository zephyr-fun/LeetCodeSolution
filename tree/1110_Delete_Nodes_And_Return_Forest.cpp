// 2023.05.30
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
    unordered_set<int> set;
    vector<TreeNode*> res;

    TreeNode* dfs(TreeNode* cur) {
        if(cur == nullptr) {
            return nullptr;
        }
        cur->left = dfs(cur->left);
        cur->right = dfs(cur->right);
        if(!set.count(cur->val)) {
            return cur;
        }
        if(cur->left) {
            res.emplace_back(cur->left);
        }
        if(cur->right) {
            res.emplace_back(cur->right);
        }
        return nullptr;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto& num : to_delete) {
            set.insert(num);
        }
        if(dfs(root)) {
            res.emplace_back(root);
        }
        return res;
    }
};