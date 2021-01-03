/*** 
 * Author: zephyr
 * Date: 2020-12-28 08:56:05
 * LastEditors: zephyr
 * LastEditTime: 2021-01-03 09:13:53
 * FilePath: \tree\98_Validate_Binary_Search_Tree.cpp
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
// 2nd 
// recursion
// 把每次的上下界保存在了lower和upper中，其实是在不断地划分小范围
bool helper(TreeNode* root, long long lower, long long upper)
{
    if(root == nullptr)// root为空，一定是BST
        return true;
    if(root->val >= upper || root->val <= lower)// root的值不在范围内，不符合BST要求
        return false;
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);// root的左子树和右子树都是BST，整棵树才是BST
}
bool isValidBST(TreeNode* root)
{
    return helper(root, LONG_MIN, LONG_MAX);// 给定上下界
}

// non recursion
// 保证中序遍历的每一个结果都小于前一个结果即可
bool isValidBST(TreeNode* root)
{
    long long preVal = (long long)INT_MIN - 1; // 初始化preVal需要谨慎，INT_MIN显然不行
    stack<TreeNode*> stk;
    while(!stk.empty() || root != nullptr)// 中序遍历
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();// 对根节点操作
        stk.pop();
        if(root->val <= preVal)// 和前一个结果比较
            return false;
        preVal = root->val;// 更新preVal
        root = root->right;// 去到右节点
    }
    return true;
}