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