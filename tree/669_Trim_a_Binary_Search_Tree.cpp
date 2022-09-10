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
// 2022.03.22
// recursion
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val > high){
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        if(root->val < low){
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        root->left = trimBST(root->left, low, high); // reconstruct tree structure
        root->right = trimBST(root->right, low, high); // reconstruct tree structure
        return root;
    }
};

// non recursion
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return nullptr;
        }
        while(root != nullptr && (root->val < low || root->val >high)){
            if(root->val < low){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        // now root->val in [low, high]
        // trim left sub tree
        TreeNode* cur = root;
        while(cur != nullptr){
            while(cur->left != null && cur->left->val < low){
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        // trim right sub tree
        while(cur != nullptr){
            while(cur->right != nullptr && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val < low) {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

// 2022.09.10
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val < low) {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};