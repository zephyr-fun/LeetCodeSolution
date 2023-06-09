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

// 2022.10.14
// O(n ^ 2)
// dfs1 O(n), dfs2 O(n)
class Solution {
public:
    int res = 0;

    void dfs1(TreeNode* root, long long targetSum) {
        if(root == nullptr) {
            return ;
        }
        dfs2(root, targetSum);
        dfs1(root->left, targetSum);
        dfs1(root->right, targetSum);
    }

    void dfs2(TreeNode* root, long long targetSum) {
        if(root == nullptr) {
            return ;
        }
        targetSum -= root->val;
        if(targetSum == 0) {
            res++;
        }
        dfs2(root->left, targetSum);
        dfs2(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs1(root, (long long)targetSum);
        return res;
    }
};

// preSum
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
class Solution {
public:
    unordered_map<long long, int> map;

    int dfs(TreeNode* root, long long cur, int tar) {
        if(root == nullptr) {
            return 0;
        }
        int temp = 0;
        cur += root->val;
        temp += map[cur - tar];
        map[cur]++;
        temp += dfs(root->left, cur, tar);
        temp += dfs(root->right, cur, tar);
        map[cur]--; // avoid tow direction search
        return temp;
    }

    int pathSum(TreeNode* root, int targetSum) {
        map[0] = 1; // prefix
        return dfs(root, 0, targetSum);
    }
};

// 2023.06.09
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
class Solution {
public:
    int target;
    int res;
    unordered_map<long long, int> map;

    void dfs(TreeNode* root, long long sum) {
        if(root == nullptr) {
            return ;
        }
        long long cur = sum + root->val;
        res += map[cur - target];
        map[cur]++;
        dfs(root->left, cur);
        dfs(root->right, cur);
        map[cur]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        res = 0;
        map[0] = 1;
        dfs(root, 0);
        return res;
    }
};