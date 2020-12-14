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