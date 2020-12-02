/*** 
 * Author: zephyr
 * Date: 2020-12-02 08:42:46
 * LastEditors: zephyr
 * LastEditTime: 2020-12-02 09:02:15
 * FilePath: \LeetCodeSolution\tree\107_Binary_Tree_Level_Order_Traversal_ii.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if(!root)
        return res;
    q.push(root);
    while(!q.empty())
    {
        int levelSize = q.size();
        vector<int> levelVal;
        for(int i = 1; i<= levelSize; i++)
        {
            auto node = q.front();
            q.pop();
            levelVal.emplace_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.emplace_back(levelVal);
    }
    reverse(res.begin(),res.end());
    return res;
}