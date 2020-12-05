/*** 
 * Author: zephyr
 * Date: 2020-12-05 12:06:33
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 12:08:13
 * FilePath: \LeetCodeSolution\tree\114_Flatten_Binary_Tree_to_Linked_List.cpp
 */
#include <iostream>
#include <vector>
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
void flatten(TreeNode* root)
{
    vector<TreeNode*> l;
    preorderTraversal(root, l);
    int n = l.size();
    for (int i = 1; i < n; i++)
    {
        TreeNode *prev = l.at(i - 1), *curr = l.at(i);
        prev->left = nullptr;
        prev->right = curr;
    }
}

void preorderTraversal(TreeNode* root, vector<TreeNode*> &l)
{
    if (root != NULL)
    {
        l.push_back(root);
        preorderTraversal(root->left, l);
        preorderTraversal(root->right, l);
    }
}