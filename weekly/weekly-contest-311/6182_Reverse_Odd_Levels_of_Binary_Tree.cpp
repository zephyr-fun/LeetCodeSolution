// 2022.09.18
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
    TreeNode* build(vector<int>& temp, int cur) {
        if(cur >= temp.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(temp[cur]);
        root->left = build(temp, 2 * cur + 1);
        root->right = build(temp, 2 * cur + 2);
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> temp;
        queue<TreeNode*> que;
        que.push(root);
        int layer = 0;
        while(!que.empty()) {
            int size = que.size();
            vector<int> tt;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                tt.emplace_back(cur->val);
                if(cur->left != nullptr) {
                    que.push(cur->left);
                }
                if(cur->right != nullptr) {
                    que.push(cur->right);
                }
            }
            if(layer & 1) {
                reverse(tt.begin(), tt.end());
            }
            layer++;
            for(auto& t : tt) {
                temp.emplace_back(t);
            }
        }
        TreeNode* res = build(temp, 0);
        return res;
    }
};

// another way, dfs
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
    void traversal(TreeNode* left, TreeNode* right, int layer) {
        if(left == nullptr || right == nullptr) {
            return ;
        }
        if(layer & 1) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        traversal(left->left, right->right, layer + 1);
        traversal(left->right, right->left, layer + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        traversal(root->left, root->right, 1);
        return root;
    }
};