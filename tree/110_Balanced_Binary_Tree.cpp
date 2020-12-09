/*** 
 * Author: zephyr
 * Date: 2020-12-09 08:59:00
 * LastEditors: zephyr
 * LastEditTime: 2020-12-09 09:32:09
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\110_Balanced_Binary_Tree.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;
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

// recursion from top to bottom
int height(TreeNode* root)
{
    if(!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(TreeNode* root)
{
    if(!root)
        return true;
    return abs(height(root->left)-height(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
}

// recursion from bottom to top avoid repeated computing
int height2(TreeNode* root)
{
    if(!root)
        return 0;
    int leftHeight = height2(root->left);
    int rightHeight = height2(root->right);
    if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight-rightHeight)>1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced2(TreeNode* root)
{
    return height(root) >= 0;
}

// pure version
bool isBalanced3(TreeNode* root) {
    return !root ? true : abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
int depth3(TreeNode* cur) { //maximum depth
    return !cur ? 0 : max(depth(cur->left), depth(cur->right)) + 1;
}