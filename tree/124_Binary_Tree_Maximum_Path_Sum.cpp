/*** 
 * Author: zephyr
 * Date: 2020-11-30 09:23:39
 * LastEditors: zephyr
 * LastEditTime: 2020-11-30 09:24:36
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\124_Binary_Tree_Maximum_Path_Sum.cpp
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

int ans = INT_MIN;
int oneSideMax(TreeNode* root) 
{
    if(root == nullptr)
        return 0;
    int left = max(0,oneSideMax(root->left));
    int right = max(0,oneSideMax(root->right));
    ans = ans>(left+right+root->val)?ans:(left+right+root->val);
    return (left>right?left:right) + root->val;
}
int maxPathSum(TreeNode* root) 
{
    oneSideMax(root);
    return ans;
}
