/*** 
 * Author: zephyr
 * Date: 2020-12-14 17:03:36
 * LastEditors: zephyr
 * LastEditTime: 2020-12-14 17:50:29
 * FilePath: \LeetCodeSolution\tree\222_Count_Complete_Tree_Nodes.cpp
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

int countNodes(TreeNode* root)
{
    if(!root)
        return 0;
    int level = 0;
    TreeNode* node = root;
    while(node->left)
    {
        level++;
        node = node->left;
    }
    int left = 1 << level;
    int right = (1 << (level + 1)) - 1;//优先级-大于>><<
    while(left < right)
    {
        int mid = (right - left + 1)/2 + left;
        if(exists(root, level, mid))
            left = mid;
        else
            right = mid - 1;
    }
    return left;   
}
bool exists(TreeNode* root, int level, int mid)
{
    int bit = 1 << (level-1);
    TreeNode* node = root;
    while(node && (bit > 0))
    {
        if(!(bit & mid))
            node = node->left;
        else
            node = node->right;
        bit = bit >> 1;
    }
    return node != nullptr;
}