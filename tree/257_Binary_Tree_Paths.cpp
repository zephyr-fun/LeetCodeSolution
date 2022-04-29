/*** 
 * Author: zephyr
 * Date: 2020-12-16 09:26:24
 * LastEditors: zephyr
 * LastEditTime: 2020-12-16 09:40:45
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\257_Binary_Tree_Paths.cpp
 */
#include <iostream>
#include <vector>
#include <string>
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
// recursion
void buildPath(TreeNode* root, string path, vector<string>& res)// mark that vector<string>& res ,has a &
{
    if(root)
    {
        path += to_string(root->val);
        if(!root->left && !root->right)
        {
            res.emplace_back(path);
        }
        else
        {
            path += "->";
            buildPath(root->left, path, res);
            buildPath(root->right, path, res);
        }
    }
    
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    buildPath(root, "", res);
    return res;
}

// with queue
vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> res;
    if(!root)
        return res;
    queue<TreeNode*> q_node;
    queue<string> q_path;
    string temp;
    temp += to_string(root->val);
    q_node.push(root);
    q_path.push(temp);
    while(!q_node.empty())
    {
        auto node = q_node.front();
        q_node.pop();
        auto path = q_path.front();
        q_path.pop();
        if(node->left)
        {
            q_node.push(node->left);
            q_path.push(path + "->" + to_string(node->left->val));
        }
        if(node->right)
        {
            q_node.push(node->right);
            q_path.push(path + "->" + to_string(node->right->val));
        }
        if(!node->left && !node->right)
            res.emplace_back(path);
    }
    return res;
}

// 2022.03.18
// recursion backtrack
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr){
            return res;
        }
        vector<int> path;
        preorderTraversal(root, path, res);
        return res;
    }
    void preorderTraversal(TreeNode* node, vector<int>& path, vector<string>& res){
        //preorder op
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            string temp;
            for(int i = 0; i < path.size() - 1; i++){
                temp += to_string(path[i]);
                temp += "->";
            }
            temp += to_string(path[path.size() - 1]);
            res.push_back(temp);
        }
        if(node->left != nullptr){
            preorderTraversal(node->left, path, res);
            path.pop_back(); // backtrack
        }
        if(node->right != nullptr){
            preorderTraversal(node->right, path, res);
            path.pop_back(); //backtrack
        }
    }
};

//  non recursion
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while(!treeSt.empty()){
            TreeNode* node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if(node->left == nullptr && node->right == nullptr){
                res.push_back(path);
            }
            if(node->left != nullptr){
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
            if(node->right != nullptr){
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
        }
        return res;
    }
};

// 2022.04.29
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& path, vector<string>& res) {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            string temp;
            for(int i = 0; i < path.size() - 1; i++) {
                temp += to_string(path[i]);
                temp += "->";
            }
            temp += to_string(path[path.size() - 1]);
            res.push_back(temp);
        }
        if(root->left != nullptr) {
            traversal(root->left, path, res);
            path.pop_back();
        }
        if(root->right != nullptr) {
            traversal(root->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) {
            return res;
        }
        vector<int> path;
        traversal(root, path, res);
        return res;
    }
};