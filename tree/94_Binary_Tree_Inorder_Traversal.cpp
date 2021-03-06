/*** 
 * Author: zephyr
 * Date: 2020-11-27 17:12:12
 * LastEditors: zephyr
 * LastEditTime: 2021-01-02 09:22:14
 * FilePath: \tree\94_Binary_Tree_Inorder_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// way 1 Recursion 
void inorder(TreeNode* root, vector<int>& res)
{
    if(!root)
        return ;
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

// way 2 Non Recursion 1
vector<int> inorderTraversal(TreeNode* root)
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

// way3 Non recursion 2
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> stk;
    while(!stk.empty() || root != nullptr)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        result.emplace_back(root->val);
        root = root->right;
    }
    return result;
}