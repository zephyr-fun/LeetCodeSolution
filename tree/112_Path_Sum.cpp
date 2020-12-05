/*** 
 * Author: zephyr
 * Date: 2020-12-05 16:39:08
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 16:56:23
 * FilePath: \LeetCodeSolution\tree\112_Path_Sum.cpp
 */
#include <iostream>
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

//BFS
bool hasPathSum(TreeNode* root, int sum)
{
    if(root == nullptr)
        return false;
    queue<TreeNode*> que_node;
    queue<int> que_val;
    que_node.push(root);
    que_val.push(root->val);
    while(!que_node.empty())
    {
        auto node = que_node.front();
        auto temp = que_val.front();
        que_node.pop();
        que_val.pop();
        if(node->left == nullptr && node->right == nullptr)
        {
            if(temp == sum)
                return true;
            continue;
        }
        if(node->left)
        {
            que_node.push(node->left);
            que_val.push(temp + node->left->val);
        }
        if(node->right)
        {
            que_node.push(node->right);
            que_val.push(temp + node->right->val);
        }
    }
    return false;
}

//recursion
bool hasPathSum2(TreeNode* root, int sum)
{
    if(root == nullptr)
        return false;
    if(root->left == nullptr && root->right == nullptr)
    {
        if(root->val == sum)
            return true;
        //return root->val == sum;
    }
    return hasPathSum2(root->left, sum-root->val) || hasPathSum2(root->right, sum-root->val);

}