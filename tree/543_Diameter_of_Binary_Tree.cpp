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

// 2022.07.14
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
    int res = 0;
    int oneSideMax(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int left = 0;
        int right = 0;
        if(root->left != nullptr) {
            left = oneSideMax(root->left);
        }
        if(root->right != nullptr) {
            right = oneSideMax(root->right);
        }
        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        oneSideMax(root);
        return res == 0 ? 0 : res - 1;
    }
};

// 2023.03.13
// convert to calc the number of points on a given path
class Solution {
public:
    int res = 1; //optim
    int oneSideMax(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int left = 0;
        int right = 0;
        if(root->left) {
            left = oneSideMax(root->left);
        }
        if(root->right) {
            right = oneSideMax(root->right);
        }
        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        oneSideMax(root);
        return res - 1;
    }
};