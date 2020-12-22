/*** 
 * Author: zephyr
 * Date: 2020-12-22 17:00:47
 * LastEditors: zephyr
 * LastEditTime: 2020-12-22 17:02:51
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\543_Diameter_of_Binary_Tree.cpp
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
// recursion
int max_length = 0; // record the longest path
int oneSideMaxLength(TreeNode* root)
{
    if(!root)
        return 0;
    int left = oneSideMaxLength(root->left);
    int right = oneSideMaxLength(root->right);
    max_length = max(max_length, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    oneSideMaxLength(root);
    return max_length;
}