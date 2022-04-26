/*** 
 * Author: zephyr
 * Date: 2020-12-14 19:23:27
 * LastEditors: zephyr
 * LastEditTime: 2020-12-14 19:24:30
 * FilePath: \LeetCodeSolution\tree\226.cpp
 */
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// 2022.03.17
// both preorder traversal and postorder traversal works
// recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
// non recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(node != nullptr){
                stk.pop();
                stk.push(node);
                stk.push(nullptr);
                if(node->right != nullptr){
                    stk.push(node->right);
                }
                if(node->left != nullptr){
                    stk.push(node->left);
                }

            }
            else{
                stk.pop();
                node = stk.top();
                stk.pop();
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
        return root;
    }
};
// level traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

// 2022.03.23
// recursion, non recursion, level traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    void helper(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        helper(root->left);
        helper(root->right);
    }
};

// 2022.04.26
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == nullptr) {
//             return nullptr;
//         }
//         root->left = invertTree(root->right);
//         root->right = invertTree(root->left);// root->left already changes
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};