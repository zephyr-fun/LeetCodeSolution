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
        int mid = (right - left + 1) / 2 + left;
        if(exists(root, level, mid))
            left = mid;
        else
            right = mid - 1;
    }
    return left;   
}
bool exists(TreeNode* root, int level, int mid)
{
    int bit = 1 << (level - 1);
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

// 2022.03.18
// utilize the feature of CBT
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left){
            left = left->left;
            leftHeight++;
        }
        while(right){
            right = right->right;
            rightHeight++;
        }
        // judge if a CBT is a FBT
        if(leftHeight == rightHeight){
            return (2 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 2022.04.29
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left != nullptr) {
            left = left->left;
            leftHeight++;
        }
        while(right != nullptr) {
            right = right->right;
            rightHeight++;
        }
        if(leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1; // notice that left now equals nullptr
    }
};

// 2023.01.16
// normal
class Solution {
public:
    int res = 0;
    void traversal(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }
        res++;
        traversal(root->left);
        traversal(root->right);
    }
    int countNodes(TreeNode* root) {
        traversal(root);
        return res;
    }
};

// optim
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftCnt = 0;
        int rightCnt = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left) {
            leftCnt++;
            left = left->left;
        }
        while(right) {
            rightCnt++;
            right = right->right;
        }
        if(leftCnt == rightCnt) {
            return (2 << leftCnt) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};