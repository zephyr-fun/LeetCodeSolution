/*** 
 * Author: zephyr
 * Date: 2020-12-01 22:26:48
 * LastEditors: zephyr
 * LastEditTime: 2020-12-01 22:30:25
 * FilePath: \LeetCodeSolution\tree\102_Binary_Tree_Level_Order_Traversal.cpp
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
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int currentLevelSize = q.size();
        res.emplace_back(vector<int> ());
        for(int i = 1; i<=currentLevelSize; i++)
        {
            auto node = q.front();
            q.pop();
            res.back().emplace_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return res;
}