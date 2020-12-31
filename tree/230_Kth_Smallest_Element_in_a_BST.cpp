/*** 
 * Author: zephyr
 * Date: 2020-12-31 09:21:57
 * LastEditors: zephyr
 * LastEditTime: 2020-12-31 09:46:03
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\230_Kth_Smallest_Element_in_a_BST.cpp
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

// way 1 recursion
vector<int> res;
void helper(TreeNode* root)
{
    if(!root)
        return ;
    helper(root->left);
    res.emplace_back(root->val);
    helper(root->right);
}
int kthSmallest(TreeNode* root, int k) {
    helper(root);
    return res[k-1];
}

// way 2 non recursion
int kthSmallest(TreeNode* root, int k)
{
    stack<TreeNode*> stk;
    while(true)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(--k == 0)
            return root->val;
        root = root->right;
    }
}