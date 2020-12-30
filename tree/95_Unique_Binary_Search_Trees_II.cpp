/*** 
 * Author: zephyr
 * Date: 2020-12-30 09:01:07
 * LastEditors: zephyr
 * LastEditTime: 2020-12-30 09:02:59
 * FilePath: \tree\95_.cpp
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