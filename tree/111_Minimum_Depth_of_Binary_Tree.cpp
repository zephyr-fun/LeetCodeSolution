/*** 
 * Author: zephyr
 * Date: 2020-12-05 10:18:42
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 10:59:38
 * FilePath: \LeetCodeSolution\tree\111_Minimum_Depth_of_Binary_Tree.cpp
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
int minDepth(TreeNode* root)
{
    if(!root)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 1;
    int min_depth = INT_MAX;
    if(root->left)
        min_depth = min(minDepth(root->left), min_depth);
    if(root->right)
        min_depth = min(minDepth(root->right), min_depth);
    return min_depth + 1;
}
int minDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty())
    {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++)
        {
            auto node = q.front();
            q.pop();
            if(node->left == nullptr && node->right == nullptr)
                return level + 1;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        level += 1;
    }
    return 0;
}