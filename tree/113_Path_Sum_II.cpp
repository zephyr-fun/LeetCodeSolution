/*** 
 * Author: zephyr
 * Date: 2020-12-07 08:52:30
 * LastEditors: zephyr
 * LastEditTime: 2020-12-07 09:25:12
 * FilePath: \LeetCodeSolution\tree\113_Path_Sum_II.cpp
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
// DFS
vector<vector<int>> res;
vector<int> path;
void dfs(TreeNode* root, int sum)
{
    if(!root)
        return ;
    path.emplace_back(root->val);
    sum -= root->val;
    if(root->left == nullptr && root->right == nullptr && sum == 0)
        res.emplace_back(path);
    dfs(root->left, sum);
    dfs(root->right, sum);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    dfs(root, sum);
    return res;
}

// BFS
vector<vector<int>> res;
unordered_map<TreeNode*, TreeNode*> parent;
void getPath(TreeNode* node)
{
    vector<int> temp;
    while(node)
    {
        temp.emplace_back(node->val);
        node = parent[node];
    }
    reverse(temp.begin(), temp.end());
    res.emplace_back(temp);
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(!root)
        return res;
    queue<TreeNode*> que_node;
    queue<int> que_sum;
    que_node.emplace(root);
    que_sum.emplace(0);
    while(!que_node.empty())
    {
        auto node = que_node.front();
        auto tempsum = que_sum.front();
        que_node.pop();
        que_sum.pop();
        tempsum += node->val;
        if(node->left == nullptr && node->right == nullptr && tempsum == sum)
            getPath(node);
        if(node->left)
        {
            parent[node->left] = node;
            que_node.push(node->left);
            que_sum.push(tempsum);
        }
        if(node->right)
        {
            parent[node->right] = node;
            que_node.push(node->right);
            que_sum.push(tempsum);
        }
    }
    return res;
}

// 2022.03.19
// recursion
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        vector<int> path;
        traversal(root, targetSum, res, path);
        return res;
    }
    void traversal(TreeNode* node, int rest, vector<vector<int>>& res, vector<int>& path){
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            if(rest - node->val == 0){
                res.push_back(path);
                return ;
            }
            else{
                return ;
            }
        }
        if(node->left != nullptr){
            traversal(node->left, rest - node->val, res, path);
            path.pop_back(); // backtrack
        }
        if(node->right != nullptr){
            traversal(node->right, rest - node->val, res, path);
            path.pop_back(); // backtrack
        }
    }
};

// non recursion remains something wrong
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        vector<int> path;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while(!st.empty()){
            pair<TreeNode*, int> node = st.top();
            path.push_back(node.first->val);
            if(node.first->left == nullptr && node.first->right == nullptr){
                if(node.second == targetSum){
                    res.push_back(path);
                    path.pop_back();
                }
                else{
                    path.pop_back();
                }
            }
            if(node.first->left != nullptr){
                st.push(pair<TreeNode*, int>(node.first->left, node.first->left->val + node.second));
                path.pop_back();
            }
            if(node.first->right != nullptr){
                st.push(pair<TreeNode*, int>(node.first->right, node.first->right->val + node.second));
                path.pop_back();
            }
        }
        return res;
    }
};

// 2022.04.29
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* root, int rest) {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(rest - root->val == 0) {
                res.push_back(path);
            }
        }
        if(root->left != nullptr) {
            traversal(root->left, rest - root->val);
            path.pop_back();
        }
        if(root->right != nullptr) {
            traversal(root->right, rest - root->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return res;
        }
        traversal(root, targetSum);
        return res;
    }
};