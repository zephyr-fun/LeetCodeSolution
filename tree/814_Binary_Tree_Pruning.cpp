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

// 2023.03.24
class Solution {
public:
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 0;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if(left == 0) {
            cur->left = nullptr;
        }
        if(right == 0) {
            cur->right = nullptr;
        }
        return left + right + cur->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(traversal(root) == 0) {
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
        if(root->left || root->right) {
            return root;
        }
        return root->val == 0 ? nullptr : root;
    }
};