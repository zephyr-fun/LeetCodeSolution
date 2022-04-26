/*** 
 * Author: zephyr
 * Date: 2020-12-01 20:28:07
 * LastEditors: zephyr
 * LastEditTime: 2020-12-01 20:47:14
 * FilePath: \LeetCodeSolution\tree\144_Binary_Tree_Preorder_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
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
//recursion
int preorderTraversal1(TreeNode* root, vector<int>& res)
{
    if(root == nullptr)
        return 0;
    res.emplace_back(root->val);
    preorderTraversal1(root->left, res);
    preorderTraversal1(root->right, res);
    return 0;
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    preorderTraversal1(root, res);
    return res;
}

//non recursion
vector<int> preorderTraversal2(TreeNode* root)
{
    vector<int> res;
    stack<pair<TreeNode*, int>> stk;
    stk.push(make_pair(root, 0));
    while(!stk.empty())
    {
        auto [node, type] = stk.top();
        stk.pop();
        if(node == nullptr)
            continue;
        if(type == 0)
        {
            stk.push(make_pair(node->right, 0));
            stk.push(make_pair(node->left, 0));
            stk.push(make_pair(node, 1));
        }
        else
        {
            res.emplace_back(node->val);
        }
        
    }
    return res;
}
// 2022.03.14
// recursion, non recursion, Morris

// recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recursionTraversal(root, res);
        return res;
    }
    void recursionTraversal(TreeNode* root, vector<int>& res){
        if(root == nullptr){
            return ;
        }
        res.push_back(root->val);
        recursionTraversal(root->left, res);
        recursionTraversal(root->right, res);
    }
};

// non recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        if(root != nullptr){
            st.push(root);
        }
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr){
                st.pop();
                //preorder traversal, push in stack like right, left, middle
                if(node->right != nullptr){
                    st.push(node->right);
                }
                if(node->left != nullptr){
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);
            }
            else{
                //deal with the current node
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
}

//Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode* temp = root->left;
                while(temp->right != nullptr && temp->right != root){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    temp->right = root;
                    //preorder
                    res.push_back(root->val);
                    root = root->left;
                }
                else{
                    temp->right = nullptr;
                    root = root->right;
                }
            }
            else{
                //preorder
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
}

// 2022.04.26
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// recursion
class Solution{
public:
    void traversal(TreeNode* root, vector<int>& res) {
        if(root == nullptr) {
            return ;
        }
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

// non recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();
                // right
                if(node->right != nullptr) {
                    st.push(node->right);
                }
                // left
                if(node->left != nullptr) {
                    st.push(node->left);
                }
                // mid
                st.push(node);
                st.push(nullptr);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

// Morris
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root != nullptr) {
            if(root->left != nullptr) {
                TreeNode* temp = root->left;
                while(temp->right != nullptr && temp->right != root) {
                    temp = temp->right;
                }
                if(temp->right == nullptr) {
                    temp->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }
                else {
                    temp->right = nullptr;
                    root = root->right;
                }
            }
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};