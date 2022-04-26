/*** 
 * Author: zephyr
 * Date: 2020-12-01 22:26:48
 * LastEditors: zephyr
 * LastEditTime: 2021-01-04 09:50:08
 * FilePath: \tree\102_Binary_Tree_Level_Order_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
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
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int currentLevelSize = q.size();
        res.emplace_back(vector<int> ());
        for(int i = 1; i<=currentLevelSize; i++)
        {
            auto node = q.front();
            q.pop();
            res.back().emplace_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return res;
}

// way 2
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q_node;
    q_node.push(root);
    while(!q_node.empty())
    {
        int levelsize = q_node.size();
        vector<int> temp;
        for(int i = 0; i < levelsize; i++)
        {
            auto node = q_node.front();
            q_node.pop();
            temp.emplace_back(node->val);
            if(node->left)
                q_node.push(node->left);
            if(node->right)
                q_node.push(node->right);
        }
        res.emplace_back(temp);
    }
    return res;
}

// 2022.03.16
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            res.push(temp);
        }
        return res;
    }
};

// 2022.04.26
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != nullptr) {
                    que.push(node->left);
                }
                if(node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};