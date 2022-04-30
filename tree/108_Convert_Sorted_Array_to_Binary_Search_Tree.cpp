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

// 2022.03.22
// recursion
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return new TreeNode();
        }
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);
        return node;
    }
};

// non recursion
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return new TreeNode();
        }
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> queNode;
        queue<int> queLeft;
        queue<int> queRight;
        queNode.push(root);
        queLeft.push(0);
        queRight.push(nums.size() - 1);
        while(!queNode.empty()){
            TreeNode* node = queNode.front();
            queNode.pop();
            int left = queLeft.front();
            queLeft.pop();
            int right = queRight.front();
            queRight.pop();
            int mid = left + (right - left) / 2;
            node->val = nums[mid];
            if(left <= mid - 1){
                node->left = new TreeNode(0);
                queNode.push(node->left);
                queLeft.push(left);
                queRight.push(mid - 1);
            }
            if(right >= mid + 1){
                node->right = new TreeNode(0);
                queNode.push(node->right);
                queLeft.push(mid + 1);
                queRight.push(right);
            }
        }
        return root;
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* constructTree(vector<int>& nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = constructTree(nums, start, mid - 1);
        node->right = constructTree(nums, mid + 1, end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return nullptr;
        }
        TreeNode* res = constructTree(nums, 0, nums.size() - 1);
        return res;
    }
};