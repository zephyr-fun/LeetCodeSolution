/*** 
 * Author: zephyr
 * Date: 2020-12-01 20:27:31
 * LastEditors: zephyr
 * LastEditTime: 2020-12-01 20:57:39
 * FilePath: \LeetCodeSolution\tree\145_Binary_Tree_Postorder_Traversal.cpp
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
int postorderTraversal1(TreeNode* root, vector<int>& res)
{
    if(root == nullptr)
        return 0;
    postorderTraversal1(root->left, res);
    postorderTraversal1(root->right, res);
    res.emplace_back(root->val);
    return 0;
}
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    postorderTraversal1(root, res);
    return res;
}

//non recursion
vector<int> postorderTraversal2(TreeNode* root)
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
            stk.push(make_pair(node, 1));
            stk.push(make_pair(node->right, 0));
            stk.push(make_pair(node->left, 0));
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        recursionTraversal(root, res);
        return res;
    }
    void recursionTraversal(TreeNode* root, vector<int>& res){
        if(root == nullptr){
            return ;
        }
        recursionTraversal(root->left, res);
        recursionTraversal(root->right, res);
        res.push_back(root->val);
        return ;
    }
};

// non recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root != null){
            st.push(root);
        }
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr){
                st.pop();
                st.push(node);
                st.push(nullptr);
                if(root->right != nullptr){
                    st.push(root->right);
                }
                if(root->left != nullptr){
                    st.push(root->left);
                }
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

// Morris traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* head = root;
        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode* temp = root->left;
                while(temp->right != nullptr && temp->right != root){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    temp->right = root;
                    root = root->left;
                }
                else{
                    temp->right = nullptr;
                    // post reverse print
                    printNode(root->left, res);
                    root = root->right;
                }
            }
            else{
                root = root->right;
            }
        }
        // post reverse print
        printNode(head, res);
        return res;
    }
    void printNode(TreeNode* node, vector<int>& res){
        TreeNode* tail = reverse(node);
        TreeNode* cur = tail;
        while(cur != nullptr){
            res.push_back(cur->val);
            cur = cur->right;
        }
        reverse(tail);
    }
    TreeNode* reverse(TreeNode* node){
        TreeNode* pre = nullptr;
        TreeNode* next = nullptr;
        while(node != nullptr){
            next = node->right;
            node->right = pre;
            pre = node;
            node = next;
        }
        return pre;
    }
};

// 2022.04.26
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// recursion
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& res) {
        if(root == nullptr) {
            return ;
        }
        traversal(root->left, res);
        traversal(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

// non recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                st.push(node);
                st.push(nullptr);
                if(node->right != nullptr) {
                    st.push(node->right);
                }
                if(node->left != nullptr) {
                    st.push(node->left);
                }
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
    TreeNode* reverse(TreeNode* root) {
        TreeNode* pre;
        TreeNode* next;
        while(root != nullptr) {
            next = root->right;
            root->right = pre;
            pre = root;
            root = next;
        }
        return pre;
    }
    void printNode(TreeNode* root, vector<int>& res) {
        TreeNode* tail = reverse(root);
        TreeNode* cur = tail;
        while(cur != nullptr) {
            res.push_back(cur->val);
            cur = cur->right;
        }
        reverse(tail);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* head = root;
        while(root != nullptr) {
            if(root->left != nullptr) {
                TreeNode* temp = root->left;
                while(temp->right != nullptr && temp->right != root) {
                    temp = temp->right;
                }
                if(temp->right == nullptr) {
                    temp->right = root;
                    root = root->left;
                }
                else {
                    temp->right = nullptr;
                    printNode(root->left, res); // root->left
                    root = root->right;
                }
            }
            else {
                root = root->right;
            }
        }
        printNode(head, res);
        return res;
    }
};