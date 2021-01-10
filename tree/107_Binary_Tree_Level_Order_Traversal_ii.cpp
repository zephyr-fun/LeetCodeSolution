/*** 
 * Author: zephyr
 * Date: 2020-12-02 08:42:46
 * LastEditors: zephyr
 * LastEditTime: 2021-01-10 22:02:19
 * FilePath: \tree\107_Binary_Tree_Level_Order_Traversal_ii.cpp
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

// 2nd
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q_node;
    q_node.push(root);
    while (!q_node.empty())
    {
        int levelsize = q_node.size();
        vector<int> temp;
        for(int i = 0; i < levelsize; i++)
        {
            auto node = q_node.front();
            q_node.pop(); // dont forget pop it out
            temp.emplace_back(node->val);
            if(node->left)
                q_node.push(node->left);
            if(node->right)
                q_node.push(node->right);
        }
        res.emplace_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}