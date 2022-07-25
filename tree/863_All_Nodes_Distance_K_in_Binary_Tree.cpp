// 2022.07.25
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> map;
    vector<int> res;
    void build(TreeNode* cur) {
        if(cur->left != nullptr) {
            map[cur].emplace_back(cur->left);
            map[cur->left].emplace_back(cur);
            build(cur->left);
        }
        if(cur->right != nullptr) {
            map[cur].emplace_back(cur->right);
            map[cur->right].emplace_back(cur);
            build(cur->right);
        }
    }
    void find(TreeNode* target, TreeNode* parent, int rest) {
        if(rest == 0) {
            res.emplace_back(target->val);
            return ;
        }
        for(auto it : map[target]) {
            if(it != parent) {
                find(it, target, rest - 1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        find(target, nullptr, k);
        return res;
    }
};