/*** 
 * Author: zephyr
 * Date: 2020-12-05 16:39:08
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 16:56:23
 * FilePath: \LeetCodeSolution\tree\112_Path_Sum.cpp
 */
#include <iostream>
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

//BFS
bool hasPathSum(TreeNode* root, int sum)
{
    if(root == nullptr)
        return false;
    queue<TreeNode*> que_node;
    queue<int> que_val;
    que_node.push(root);
    que_val.push(root->val);
    while(!que_node.empty())
    {
        auto node = que_node.front();
        auto temp = que_val.front();
        que_node.pop();
        que_val.pop();
        if(node->left == nullptr && node->right == nullptr)
        {
            if(temp == sum)
                return true;
            continue;
        }
        if(node->left)
        {
            que_node.push(node->left);
            que_val.push(temp + node->left->val);
        }
        if(node->right)
        {
            que_node.push(node->right);
            que_val.push(temp + node->right->val);
        }
    }
    return false;
}

//recursion
bool hasPathSum2(TreeNode* root, int sum)
{
    if(root == nullptr)
        return false;
    if(root->left == nullptr && root->right == nullptr)
    {
        if(root->val == sum)
            return true;
        //return root->val == sum;
    }
    return hasPathSum2(root->left, sum-root->val) || hasPathSum2(root->right, sum-root->val);

}

// 2022.03.19
// recursion with strange grammar
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        return traversal(root, targetSum);
    }
    bool traversal(TreeNode* node, int rest){
        if(node->left == nullptr && node->right == nullptr){
            if(rest - node->val == 0){
                //cout << "?";
                return true;
            }
            else{
                //cout << "help";
                return false;
            }
        }
        if(node->left != nullptr){
            if(traversal(node->left, rest - node->val)){
                return true;
            }
            //cout << "node_value:" << node->left->val << "rest_value:" << rest - node->val << "bool" << left ;
        }
        if(node->right != nullptr){
            if(traversal(node->right, rest - node->val)){
                return true;
            }
            //cout << "node_value:" << node->right->val << "rest_value:" << rest - node->val << "bool" << right ;
        }
        //cout << "final:" << (left || right);
        //return bool(left || right);
        return false;
    }
};

//non recursion
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while(!st.empty()){
            pair<TreeNode*, int> node = st.top();
            st.pop();
            if(node.first->left == nullptr && node.first->right == nullptr){
                if(node.second == targetSum){
                    return true;
                }
                else{
                    continue;
                }
            }
            if(node.first->left != nullptr){
                st.push(pair<TreeNode*, int>(node.first->left, node.first->left->val + node.second));
            }
            if(node.first->right != nullptr){
                st.push(pair<TreeNode*, int>(node.first->right, node.first->right->val + node.second));
            }
        }
        return false;
    }
};