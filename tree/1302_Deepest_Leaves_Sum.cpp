// 2022.08.17
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
    int maxDepth = 0;
    vector<int> temp;
    void traversal(TreeNode* root, int depth) {
        if(root == nullptr) {
            return ;
        }
        if(depth > maxDepth) {
            maxDepth = depth;
            temp.clear();
            temp.emplace_back(root->val);
        }
        else if(depth == maxDepth) {
            temp.emplace_back(root->val);
        }
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        traversal(root, 0);
        int res = 0;
        for(auto num : temp) {
            res += num;
        }
        return res;
    }
};

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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            int temp = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp += cur->val;
                if(cur->left != nullptr) {
                    que.push(cur->left);
                }
                if(cur->right != nullptr) {
                    que.push(cur->right);
                }
            }
            res = temp;
        }
        return res;
    }
};