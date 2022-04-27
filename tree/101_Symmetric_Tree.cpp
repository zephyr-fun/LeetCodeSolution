/*** 
 * Author: zephyr
 * Date: 2020-12-01 21:20:23
 * LastEditors: zephyr
 * LastEditTime: 2021-01-04 09:13:12
 * FilePath: \tree\101_Symmetric_Tree.cpp
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

//recursion
bool check(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
}
bool isSymmetric(TreeNode* root)
{
    return check(root, root);
}

//non recursion
bool isSymmetric2(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    TreeNode* u;
    TreeNode* v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();
        if(!u && !v)
            continue;
        if((!u || !v) || u->val!=v->val)// pay attension to !u || !v
            return false;
        q.push(u->left);
        q.push(v->right);
        q.push(u->right);
        q.push(v->left);
    }
    return true;
}

// 2022.03.18
// recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return areSymmetric(root->left, root->right);
    }
    bool areSymmetric(TreeNode* left, TreeNode* right){
        if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right != nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;
        return areSymmetric(left->left, right->right) && areSymmetric(left->right, right->left);
    }
};

// make pair of each insides and outsides

// non recursion with queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == nullptr){
            return true;
        }
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if(left != nullptr && right == nullptr) return false;
            else if(left == nullptr && right != nullptr) return false;
            else if(left == nullptr && right == nullptr) continue;
            else if(left->val != right->val) return false;
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};

// non recursion with stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr){
            return true;
        }
        st.push(root->right);
        st.push(root->left);
        while(!st.empty()){
            TreeNode* left = st.top();
            st.pop();
            TreeNode* right = st.top();
            st.pop();
            if(left != nullptr && right == nullptr) return false;
            else if(left == nullptr && right != nullptr) return false;
            else if(left == nullptr && right == nullptr) continue;
            else if(left->val != right->val) return false;
            st.push(right->left);
            st.push(left->right);
            st.push(right->right);
            st.push(left->left);
        }
        return true;
    }
};

// 2022.04.27
// recursion
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right != nullptr) {
            return false;
        }
        else if(left != nullptr && right == nullptr) {
            return false;
        }
        else if(left == nullptr && right == nullptr) {
            return true;
        }
        else if(left->val != right->val){
            return false;
        }
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;

    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};

// non recursion, iteration with queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if(left == nullptr && right == nullptr) {
                continue;
            }
            if(left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};

// non recursion, iteration with stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()) {
            TreeNode* left = st.top();
            st.pop();
            TreeNode* right = st.top();
            st.pop();
            if(left == nullptr && right == nullptr) {
                continue;
            }
            if(left == nullptr || right == nullptr || left->val != right->val) {
                return false;
            }
            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }
};