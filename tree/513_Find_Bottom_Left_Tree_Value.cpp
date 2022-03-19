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
// recursion
class Solution {
public:
    int maxDepth = INT_MIN;
    int leftValue;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return leftValue;
    }
    void dfs(TreeNode* node, int depth){
        if(node->left == nullptr && node->left == nullptr){
            if(depth > maxDepth){
                maxDepth = depth; // remember to update maxDepth
                leftValue = node->val;
            }
        }
        if(node->left != nullptr){
            dfs(node->left, depth + 1); // include backtrack in 'depth + 1'
        }
        if(node->right != nullptr){
            dfs(node->right, depth + 1); // include backtrack in 'depth + 1'
        }
    }
};

// levelOrder traversal
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == 0){
                    res = node->val;
                }
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};