/*** 
 * Author: zephyr
 * Date: 2020-12-29 08:55:28
 * LastEditors: zephyr
 * LastEditTime: 2020-12-29 09:15:22
 * FilePath: \tree\173_Binary_Search_Tree_Iterator.cpp
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        left_helper(root);
    }
    
    int next() {
        TreeNode* topnode = stk.top();
        stk.pop();
        if(topnode->right != nullptr)
        {
            left_helper(topnode->right);
        }
        return topnode->val;
    }
    
    bool hasNext() {
        return stk.size() > 0;
    }
private:
    void left_helper(TreeNode* root)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// 2022.10.21
// in order traversal(non recursion)
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        dfsLeft(root);
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        if(cur->right != nullptr) {
            dfsLeft(cur->right);
        }
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void dfsLeft(TreeNode* root) {
        while(root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */