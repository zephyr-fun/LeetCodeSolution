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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool re = false;
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp.emplace_back(cur->val);
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            if(re) {
                reverse(temp.begin(), temp.end());
            }
            re = !re;
            res.emplace_back(temp);
        }
        return res;
    }
};

// 2022.08.12
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        bool re = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp.emplace_back(cur->val);
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            if(re) {
                reverse(temp.begin(), temp.end());
            }
            re = !re;
            res.emplace_back(temp);
        }
        return res;
    }
};

// optim
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        bool re = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp(size);
            for(int i = re ? size - 1 : 0; re ? i >= 0 : i < size; re ? i-- : i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp[i] = cur->val;
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            re = !re;
            res.emplace_back(temp);
        }
        return res;
    }
};