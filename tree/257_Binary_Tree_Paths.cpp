/*** 
 * Author: zephyr
 * Date: 2020-12-16 09:26:24
 * LastEditors: zephyr
 * LastEditTime: 2020-12-16 09:28:45
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\257_Binary_Tree_Paths.cpp
 */
#include <iostream>
#include <vector>
#include <string>
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