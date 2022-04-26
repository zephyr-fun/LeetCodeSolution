/*** 
 * Author: zephyr
 * Date: 2020-12-14 15:06:16
 * LastEditors: zephyr
 * LastEditTime: 2020-12-14 15:24:09
 * FilePath: \LeetCodeSolution\tree\199_Binary_Tree_Right_side_view.cpp
 */
#include <queue>
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
// BFS
vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if(!root)
        return res;
    queue<TreeNode*> levelTraversal;
    levelTraversal.push(root);
    while(!levelTraversal.empty())
    {
        int levelSize = levelTraversal.size();
        TreeNode* node;
        for(int i = 0; i < levelSize; i++)
        {
            node = levelTraversal.front();
            levelTraversal.pop();
            if(node->left)
                levelTraversal.push(node->left);
            if(node->right)
                levelTraversal.push(node->right);
        }
        res.emplace_back(node->val);
    }
    return res;
}

// DFS
vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if(!root)
        return res;
    unordered_map<int, int>firstAtDepth;
    int max_depth = -1;
    stack<TreeNode*> depthNode;
    stack<int> depthStack;
    depthNode.push(root);
    depthStack.push(0);
    while(!depthNode.empty())
    {
        auto node = depthNode.top();
        depthNode.pop();
        auto depth = depthStack.top();
        depthStack.pop();
        max_depth = max(depth, max_depth);
        if(firstAtDepth.find(depth) == firstAtDepth.end())
            firstAtDepth[depth] = node->val;
        if(node->left)
        {
            depthNode.push(node->left);
            depthStack.push(depth + 1);
        }
        if(node->right)
        {
            depthNode.push(node->right);
            depthStack.push(depth + 1);
        }
    }
    for(int i = 0; i <= max_depth; i++)
    {
        res.emplace_back(firstAtDepth[i]);
    }
    return res;
}

// 2022.03.16
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == size - 1){
                    res.push_back(node->val);
                }
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};

// 2022.04.26
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(i == size - 1) {
                    res.push_back(node->val);
                }
                if(node->left != nullptr) {
                    que.push(node->left);
                }
                if(node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }
        return res;
    }
};