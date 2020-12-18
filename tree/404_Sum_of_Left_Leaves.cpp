/*** 
 * Author: zephyr
 * Date: 2020-12-18 20:47:40
 * LastEditors: zephyr
 * LastEditTime: 2020-12-18 21:04:30
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\404_Sum_of_Left_Leaves.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
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
bool isLeafNode(TreeNode* node)
{
    return !node->left && !node->right;
}
int dfs(TreeNode* node)
{
    int res = 0;
    if(node->left)
        res += isLeafNode(node->left)?node->left->val:dfs(node->left);
    if(node->right && !isLeafNode(node->right))
        res += dfs(node->right);
    return res;
}
int sumOfLeftLeaves(TreeNode* root) {
    if(!root)
        return 0;
    return dfs(root);
}
// non recursion
bool isLeafNode(TreeNode* node) {
    return !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) {
            if (isLeafNode(node->left)) {
                ans += node->left->val;
            }
            else {
                q.push(node->left);
            }
        }
        if (node->right) {
            if (!isLeafNode(node->right)) {
                q.push(node->right);
            }
        }
    }
    return ans;
}