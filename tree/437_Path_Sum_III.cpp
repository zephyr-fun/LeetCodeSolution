/*** 
 * Author: zephyr
 * Date: 2020-12-19 10:23:26
 * LastEditors: zephyr
 * LastEditTime: 2020-12-19 10:33:08
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\437_Path_Sum_III.cpp
 */
#include <iostream>
#include <unordered_map>
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
unordered_map<int, int> prefixSum;
int dfs(TreeNode* root, int current, int target)
{
    if(!root)
        return 0;
    int temp = 0;
    current += root->val;
    temp += prefixSum[current - target];
    prefixSum[current]++;
    temp += dfs(root->left, current, target);
    temp += dfs(root->right, current, target);
    prefixSum[current]--;
    return temp;
}
int pathSum(TreeNode* root, int sum)
{
    prefixSum[0] = 1;
    return dfs(root, 0, sum);
}