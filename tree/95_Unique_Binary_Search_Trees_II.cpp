/*** 
 * Author: zephyr
 * Date: 2020-12-30 09:01:07
 * LastEditors: zephyr
 * LastEditTime: 2021-01-02 09:55:05
 * FilePath: \tree\95_Unique_Binary_Search_Trees_II.cpp
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// 1st
vector<TreeNode*> generateTrees(int start, int end)
{
    if(start > end)
        return {nullptr};
    vector<TreeNode*> allTrees;
    for(int i = start; i <= end; i++)
    {
        vector<TreeNode*> leftTrees = generateTrees(start, i-1);
        vector<TreeNode*> rightTrees = generateTrees(i+1, end);
        for(auto& left : leftTrees)
            for(auto& right : rightTrees)
            {
                TreeNode* currentTree = new TreeNode(i);
                currentTree->left = left;
                currentTree->right = right;
                allTrees.emplace_back(currentTree);
            }
    }
    return allTrees;
}
vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
        return {};
    return generateTrees(1, n);
}

// 2nd
vector<TreeNode*> generateTrees(int start, int end)
{
    if(start > end)
        return {nullptr};
    // allTrees store all fine trees
    vector<TreeNode*> allTrees;
    for(int i = start; i <= end; i++)
    {
        vector<TreeNode*> leftTrees = generateTrees(start, i-1);// current root i
        vector<TreeNode*> rightTrees = generateTrees(i+1, end);// (start, i-1)-i-(i+1, end)
        for(auto left : leftTrees)
            for(auto right : rightTrees)
            {
                TreeNode* currTree = new TreeNode(i);
                currTree->left = left;
                currTree->right = right;
                allTrees.emplace_back(currTree);// add root(i)
            }
    }
    return allTrees;
}
vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
        return {};
    return generateTrees(1, n);
}