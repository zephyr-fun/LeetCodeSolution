/*** 
 * Author: zephyr
 * Date: 2020-12-01 20:27:31
 * LastEditors: zephyr
 * LastEditTime: 2020-12-01 20:57:39
 * FilePath: \LeetCodeSolution\tree\145_Binary_Tree_Postorder_Traversal.cpp
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
int postorderTraversal1(TreeNode* root, vector<int>& res)
{
    if(root == nullptr)
        return 0;
    postorderTraversal1(root->left, res);
    postorderTraversal1(root->right, res);
    res.emplace_back(root->val);
    return 0;
}
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    postorderTraversal1(root, res);
    return res;
}

//non recursion
vector<int> postorderTraversal2(TreeNode* root)
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
            stk.push(make_pair(node, 1));
            stk.push(make_pair(node->right, 0));
            stk.push(make_pair(node->left, 0));
        }
        else
        {
            res.emplace_back(node->val);
        }
        
    }
    return res;
}