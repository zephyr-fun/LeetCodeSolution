/*** 
 * Author: zephyr
 * Date: 2020-12-28 08:56:05
 * LastEditors: zephyr
 * LastEditTime: 2020-12-28 09:28:01
 * FilePath: \pytorch-fm-masterd:\GithubWorkSpace\LeetCodeSolution\tree\98_Validate_Binary_Search_Tree.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// way 1 : recursion
bool helper(TreeNode* root, long long lower, long long upper)
{
    if(root == nullptr)
        return true;
    if(root->val <= lower || root->val >= upper)
        return false;
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

// way 2 : non_recursion inorder traversal
bool isValidBST(TreeNode* root)
{
    stack<TreeNode*> stk;
    long long pre_val = (long long)INT_MIN - 1;
    while(!stk.empty() || root != nullptr)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(root->val <= pre_val)
            return false;
        pre_val = root->val;
        root = root->right;
    }
    return true;
}