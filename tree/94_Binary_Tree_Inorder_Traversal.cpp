/*** 
 * Author: zephyr
 * Date: 2020-11-27 17:12:12
 * LastEditors: zephyr
 * LastEditTime: 2020-11-28 11:59:53
 * FilePath: \LeetCodeSolution\tree\94_Binary_Tree_Inorder_Traversal.cpp
 */
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
#include <iostream>
#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Recursion 
void inorder(TreeNode* root, vector<int>& res)
{
    if(!root)
        return 0;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}
//Non Recursion
vector<int> inorderTraversal2(TreeNode* root)
{
    vector<int> result;
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
            stk.push(make_pair(node, 1));
            stk.push(make_pair(node->left, 0));

        }
        else
        {
            result.emplace_back(node->val);
        }
        
    }
    return result;
}