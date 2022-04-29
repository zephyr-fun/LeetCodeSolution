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
// 2022.03.21
// for any tree, recursion, did not utilize BST's feature
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        TreeNode* left = searchBST(root->left, val);
        TreeNode* right = searchBST(root->right, val);
        if(left != nullptr){
            return left;
        }
        if(right != nullptr){
            return right;
        }
        return nullptr;
    }
};
// for BST, non recursion
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* node = root;
        while(node != nullptr){
            if(node->val == val){
                return node;
            }
            else if(node->val > val){
                node = node->left;
            }
            else if(node->val < val){
                node = node->right;
            }
        }
        return nullptr;
    }
};
// for BST, recursion
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        if(root->val < val){
            TreeNode* right = searchBST(root->right, val);
            if(right != nullptr){
                return right;
            }
        }
        if(root->val > val){
            TreeNode* left = searchBST(root->left, val);
            if(left != nullptr){
                return left;
            }
        }
        return nullptr;
    }
};

// 2022.04.29
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr) {
            if(root->val == val) {
                return root;
            }
            else if(root->val < val) {
                root = root->right;
            }
            else if(root->val > val) {
                root = root->left;
            }
        }
        return nullptr;
    }
};