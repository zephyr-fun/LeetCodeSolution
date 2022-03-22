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
// recursion
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        if(val > root->val){ // else also works
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// non recursion
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* head = root;
        TreeNode* pre = nullptr;
        while(root != nullptr){
                pre = root;
            if(root->val > val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        if(val < pre->val){
            pre->left = new TreeNode(val);
        }
        else{
            pre->right = new TreeNode(val);
        }
        return head;
    }
};