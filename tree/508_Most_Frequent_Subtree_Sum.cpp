/*** 
 * Author: zephyr
 * Date: 2020-12-22 16:32:03
 * LastEditors: zephyr
 * LastEditTime: 2020-12-22 16:35:07
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\508_Most_Frequent_Subtree_Sum.cpp
 */
#include <iostream>
#include <vector>
#include <unordered_map>
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
// post order traversal
// unordered map for <sum, frequent>
unordered_map<int, int> map;
int max_term = 0;
int findSum(TreeNode* root)
{
    if(!root)
        return 0;
    int left = findSum(root->left);
    int right = findSum(root->right);
    int sum = root->val + left + right;
    map[sum] += 1;
    //recursion
    max_term = max(max_term, map[sum]);
    return sum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    if(!root)
    {
        return res;
    }
    findSum(root);
    for(auto temp = map.begin(); temp != map.end(); temp++)
    {
        if(temp->second == max_term)
            res.emplace_back(temp->first);
    }
    return res;
}

// 2022.06.19
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
    unordered_map<int, int> map;
    vector<int> res;
    void traversalSum(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            map[root->val]++;
            return ;
        }
        int left = 0;
        int right = 0;
        if(root->left) {
            traversalSum(root->left);
            left = root->left->val;
        }
        if(root->right) {
            traversalSum(root->right);
            right = root->right->val;
        }
        root->val = left + right + root->val;
        map[root->val]++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traversalSum(root);
        int maxCnt = 1;
        for(auto it : map) {
            if(it.second > maxCnt) {
                res.clear();
                maxCnt = it.second;
                res.emplace_back(it.first);
            }
            else if(it.second == maxCnt) {
                res.emplace_back(it.first);
            }
        }
        return res;
    }
};