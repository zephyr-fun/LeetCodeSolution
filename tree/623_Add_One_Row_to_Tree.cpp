// 2022.08.05
// bfs
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        depth -= 2;
        while(!que.empty() && depth--) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
        }
        int size = que.size();
        for(int i = 0; i < size; i++) {
            TreeNode* cur = que.front();
            que.pop();
            TreeNode* left = cur->left;
            TreeNode* right = cur->right;
            cur->left = new TreeNode(val);
            cur->right = new TreeNode(val);
            cur->left->left = left;
            cur->right->right = right;
        }
        return root;
    }
};

// dfs
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
    int d;
    int v;
    void traversal(TreeNode* cur, int depth) {
        if(cur == nullptr) {
            return ;
        }
        if(depth == d - 1) {
            TreeNode* left = new TreeNode(v);
            TreeNode* right = new TreeNode(v);
            left->left = cur->left;
            cur->left = left;
            right->right = cur->right;
            cur->right = right;
        }
        else {
            traversal(cur->left, depth + 1);
            traversal(cur->right, depth + 1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        d = depth;
        v = val;
        if(depth == 1) {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        traversal(root, 1);
        return root;
    }
};