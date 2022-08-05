// 2022.08.05
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            res.emplace_back(cur->val);
            if(cur->left) {
                que.push(cur->left);
            }
            if(cur->right) {
                que.push(cur->right);
            }
        }
        return res;
    }
};