// 2022.07.21
// plain
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
    int trim(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        int left = 0;
        int right = 0;
        if(root->left != nullptr) {
            left = trim(root->left);
            if(!left) {
                root->left = nullptr;
            }
        }
        if(root->right != nullptr) {
            right = trim(root->right);
            if(!right) {
                root->right = nullptr;
            }
        }
        return left || right || root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!trim(root)) {
            return nullptr;
        }
        return root;
    }
};

// optim
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left != nullptr || root->right != nullptr) {
            return root;
        }
        return root->val == 0 ? nullptr : root;
    }
};