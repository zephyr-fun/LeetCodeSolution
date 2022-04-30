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
// recursion, reverse inorder traversal
class Solution {
public:
    TreeNode* pre;
    TreeNode* convertBST(TreeNode* root) {
        traversalSum(root);
        return root;
    }
    void traversalSum(TreeNode* node){
        if(node == nullptr){
            return ;
        }
        traversalSum(node->right);
        if(pre != nullptr){
            node->val = node->val + pre->val;
        }
        pre = node;
        //cout << "node value:" << node->val;
        traversalSum(node->left);
    }
};
// non recursion, reverse inorder traversal
class Solution {
public:
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->right;
            }
            else{
                cur = st.top();
                st.pop();
                if(pre != nullptr){
                    cur->val = cur->val + pre->val;
                }
                pre = cur;
                cur = cur->left;
            }
        }
        return root;
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* pre = nullptr;
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        if(pre != nullptr) {
            root->val += pre->val;
        }
        pre = root;
        convertBST(root->left);
        return root;
    }
};