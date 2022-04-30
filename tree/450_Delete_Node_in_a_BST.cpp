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
// recursion with BST's feature
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{ // root->left != nullptr && root->right != nullptr
                TreeNode* node = root->right;
                while(node->left != nullptr){
                    node = node->left;
                }
                node->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key); // BST's feature
        if(root->val < key) root->right = deleteNode(root->right, key); // BST's feature
        return root;
    }
};

// non recursion
class Solution {
public:
    TreeNode* deleteOneNode(TreeNode* root){
        if(root == nullptr){
            return root;
        }
        if(root->right == nullptr){
            return root->left;
        }
        TreeNode* cur = root->right;
        while(cur->left != nullptr){
            cur = cur->left;
        }
        cur->left = root->left;
        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        while(root != nullptr){
            if(root->val == key){
                break ;
            }
            pre = root;
            if(root->val > key){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        if(pre == nullptr){
            return deleteOneNode(root);
        }
        if(pre->left != nullptr && pre->left->val == key){
            pre->left = deleteOneNode(root);
        }
        if(pre->right != nullptr && pre->right->val == key){
            pre->right = deleteOneNode(root);
        }
        return node;
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val == key) {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr) {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            else if(root->right == nullptr) {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            else {
                // both side exists
                TreeNode* temp = root->right;
                while(temp->left != nullptr) {
                    temp = temp->left;
                }
                temp->left = root->left;
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
        }
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};