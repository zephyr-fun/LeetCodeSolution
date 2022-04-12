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

// 2022.04.12
// plain recursion
class Solution{
public:
    int rob(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        // rob cur
        int val1 = root->val;
        if(root->left){
            val1 += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            val1 += rob(root->right->left) + rob(root->right->right);
        }
        // not rob cur
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};

// memory recursion
class Solution {
public:
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        if(umap[root]){
            return umap[root];
        }
        // rob cur
        int val1 = root->val;
        if(root->left){
            val1 += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            val1 += rob(root->right->left) + rob(root->right->right);
        }
        // not rob cur
        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2);
    }
};

//dp
class Solution {
public:
    int rob(TreeNode* root){
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    vector<int> robTree(TreeNode* cur){
        if(cur == nullptr){
            return {0, 0};
        }
        // Subscript 0 not take, Subscript 1 take, max value
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};