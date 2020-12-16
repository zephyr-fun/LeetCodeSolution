/*** 
 * Author: zephyr
 * Date: 2020-12-16 09:26:24
 * LastEditors: zephyr
 * LastEditTime: 2020-12-16 09:40:45
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\257_Binary_Tree_Paths.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
// recursion
void buildPath(TreeNode* root, string path, vector<string>& res)// mark that vector<string>& res ,has a &
{
    if(root)
    {
        path += to_string(root->val);
        if(!root->left && !root->right)
        {
            res.emplace_back(path);
        }
        else
        {
            path += "->";
            buildPath(root->left, path, res);
            buildPath(root->right, path, res);
        }
    }
    
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    buildPath(root, "", res);
    return res;
}

// with queue
vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> res;
    if(!root)
        return res;
    queue<TreeNode*> q_node;
    queue<string> q_path;
    string temp;
    temp += to_string(root->val);
    q_node.push(root);
    q_path.push(temp);
    while(!q_node.empty())
    {
        auto node = q_node.front();
        q_node.pop();
        auto path = q_path.front();
        q_path.pop();
        if(node->left)
        {
            q_node.push(node->left);
            q_path.push(path + "->" + to_string(node->left->val));
        }
        if(node->right)
        {
            q_node.push(node->right);
            q_path.push(path + "->" + to_string(node->right->val));
        }
        if(!node->left && !node->right)
            res.emplace_back(path);
    }
    return res;
}