/*** 
 * Author: zephyr
 * Date: 2020-12-23 10:20:20
 * LastEditors: zephyr
 * LastEditTime: 2021-01-11 22:25:57
 * FilePath: \tree\108_Convert_Sorted_Array_to_Binary_Search_Tree.cpp
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

TreeNode* dfs(vector<int>& nums, int left, int right)
{
    if(left > right)
    {
        return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.empty())
        return nullptr;
    TreeNode* root = dfs(nums, 0, nums.size() - 1);
    return root;
}

// 2nd
TreeNode* dfs(vector<int>& nums, int left, int right)
{
    if(left > right)
        return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.empty())
        return nullptr;
    TreeNode* root = dfs(nums, 0, nums.size() - 1);
    return root;
}