/*** 
 * Author: zephyr
 * Date: 2020-12-14 15:06:16
 * LastEditors: zephyr
 * LastEditTime: 2020-12-14 15:12:27
 * FilePath: \LeetCodeSolution\tree\199_Binary_Tree_Right_side_view.cpp
 */
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>
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
// BFS
vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if(!root)
        return res;
    queue<TreeNode*> levelTraversal;
    levelTraversal.push(root);
    while(!levelTraversal.empty())
    {
        int levelSize = levelTraversal.size();
        TreeNode* node;
        for(int i = 0; i < levelSize; i++)
        {
            node = levelTraversal.front();
            levelTraversal.pop();
            if(node->left)
                levelTraversal.push(node->left);
            if(node->right)
                levelTraversal.push(node->right);
        }
        res.emplace_back(node->val);
    }
    return res;
}

// DFS
vector<int> rightSideView(TreeNode* root)
{
    unordered_map<int, int>firstAtDepth;
    int max_depth = -1;
    stack<TreeNode*> depthNode;
    stack<int> depthStack;
    depthNode.push(root);
    depthStack.push(0);
}