/*** 
 * Author: zephyr
 * Date: 2020-12-08 22:21:59
 * LastEditors: zephyr
 * LastEditTime: 2020-12-08 22:24:32
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\129_Sum_Root_to_Leaf_Numbers.cpp
 */
#include <iostream>
#include <queue>
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

// DFS
int res = 0;
int dfs(TreeNode* root, int temp)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        res += temp;
    }
    if(root->left)
        dfs(root->left, temp*10+root->left->val);
    if(root->right)
        dfs(root->right, temp*10+root->right->val);
    return 0;
}
int sumNumbers(TreeNode* root) {
    if(!root)
        return 0;
    dfs(root, root->val);
    return res;
}

// BFS
int res = 0;
int sumNumbers2(TreeNode* root) {
    if(!root)
        return 0;
    queue<TreeNode*> que_node;
    queue<int> que_num;
    que_node.emplace(root);
    que_num.emplace(root->val);
    while(!que_node.empty())
    {
            auto node = que_node.front();            
            que_node.pop();
            auto temp = que_num.front();
            que_num.pop();
            if(node->left == nullptr && node->right == nullptr)
                res += temp;
            if(node->left)            
            {
                que_node.push(node->left);
                que_num.push(temp*10 + node->left->val);
            }
            if(node->right)
            {
                que_node.push(node->right);
                que_num.push(temp*10 + node->right->val);
            }
    }
    return res;
}