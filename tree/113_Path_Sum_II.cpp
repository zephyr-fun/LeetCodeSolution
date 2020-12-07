/*** 
 * Author: zephyr
 * Date: 2020-12-07 08:52:30
 * LastEditors: zephyr
 * LastEditTime: 2020-12-07 09:25:12
 * FilePath: \LeetCodeSolution\tree\113_Path_Sum_II.cpp
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
// DFS
vector<vector<int>> res;
vector<int> path;
void dfs(TreeNode* root, int sum)
{
    if(!root)
        return ;
    path.emplace_back(root->val);
    sum -= root->val;
    if(root->left == nullptr && root->right == nullptr && sum == 0)
        res.emplace_back(path);
    dfs(root->left, sum);
    dfs(root->right, sum);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    dfs(root, sum);
    return res;
}

// BFS
vector<vector<int>> res;
unordered_map<TreeNode*, TreeNode*> parent;
void getPath(TreeNode* node)
{
    vector<int> temp;
    while(node)
    {
        temp.emplace_back(node->val);
        node = parent[node];
    }
    reverse(temp.begin(), temp.end());
    res.emplace_back(temp);
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(!root)
        return res;
    queue<TreeNode*> que_node;
    queue<int> que_sum;
    que_node.emplace(root);
    que_sum.emplace(0);
    while(!que_node.empty())
    {
        auto node = que_node.front();
        auto tempsum = que_sum.front();
        que_node.pop();
        que_sum.pop();
        tempsum += node->val;
        if(node->left == nullptr && node->right == nullptr && tempsum == sum)
            getPath(node);
        if(node->left)
        {
            parent[node->left] = node;
            que_node.push(node->left);
            que_sum.push(tempsum);
        }
        if(node->right)
        {
            parent[node->right] = node;
            que_node.push(node->right);
            que_sum.push(tempsum);
        }
    }
    return res;
}