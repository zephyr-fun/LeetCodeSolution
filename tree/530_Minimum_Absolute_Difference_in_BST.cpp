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
// recursion, inorder traversal, 'PRE'
class Solution {
public:
    TreeNode* pre;
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root){
        traversal(root);
        return res;
    }
    void traversal(TreeNode* node) {
        if(node == nullptr){
            return ;
        }
        traversal(node->left);
        if(pre != nullptr){
            res = min(res, (node->val - pre->val));
        }
        pre = node; // mark
        traversal(node->right);
    }
};

// non recursion
class Solution {
public:
    int getMinimumDifference(TreeNode* root){
        if(root == nullptr){
            return INT_MAX;
        }
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        int res = INT_MAX;
        stack<TreeNode*> st;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left; // most left, middle, right
            }
            else{
                cur = st.top();
                st.pop();
                if(pre != nullptr){
                    res = min(res, (cur->val - pre->val));
                }
                pre = cur; // mark
                cur = cur->right;
            }
        }
        return res;
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* pre;
    int minValue = 0x3f3f3f3f;
    void helper(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }
        helper(root->left);
        if(pre != nullptr && abs(root->val - pre->val) < minValue) {
            minValue = abs(root->val - pre->val);
        }
        pre = root;
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return minValue;
    }
};