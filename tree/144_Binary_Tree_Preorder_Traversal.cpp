/*** 
 * Author: zephyr
 * Date: 2020-12-01 20:28:07
 * LastEditors: zephyr
 * LastEditTime: 2020-12-01 20:47:14
 * FilePath: \LeetCodeSolution\tree\144_Binary_Tree_Preorder_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
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
//recursion
int preorderTraversal1(TreeNode* root, vector<int>& res)
{
    if(root == nullptr)
        return 0;
    res.emplace_back(root->val);
    preorderTraversal1(root->left, res);
    preorderTraversal1(root->right, res);
    return 0;
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    preorderTraversal1(root, res);
    return res;
}

//non recursion
vector<int> preorderTraversal2(TreeNode* root)
{
    vector<int> res;
    stack<pair<TreeNode*, int>> stk;
    stk.push(make_pair(root, 0));
    while(!stk.empty())
    {
        auto [node, type] = stk.top();
        stk.pop();
        if(node == nullptr)
            continue;
        if(type == 0)
        {
            stk.push(make_pair(node->right, 0));
            stk.push(make_pair(node->left, 0));
            stk.push(make_pair(node, 1));
        }
        else
        {
            res.emplace_back(node->val);
        }
        
    }
    return res;
}