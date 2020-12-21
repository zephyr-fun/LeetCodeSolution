/*** 
 * Author: zephyr
 * Date: 2020-12-21 17:32:19
 * LastEditors: zephyr
 * LastEditTime: 2020-12-21 17:45:00
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\dp\337_House_Robber_III.cpp
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// dfs + dp
// f(o) = g(l) + g(r)
// g(0) = max{f(l), g(l)} + max{f(r), g(r)}

unordered_map<TreeNode*, int> f, g;

void dfs(TreeNode* root)
{
    if(!root)
        return ;
    dfs(root->left);
    dfs(root->right);
    f[root] = root->val + g[root->left] + g[root->right];
    g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
}

int rob(TreeNode* root) {
    if(!root)
        return 0;
    dfs(root);
    return f[root] > g[root] ? f[root] : g[root];
}