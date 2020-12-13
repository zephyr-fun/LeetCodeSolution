/*** 
 * Author: zephyr
 * Date: 2020-12-12 14:56:36
 * LastEditors: zephyr
 * LastEditTime: 2020-12-13 10:54:38
 * FilePath: \LeetCodeSolution\tree\106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(n) using stack
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    if(!postorder.size())
    {
        return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
    stack<TreeNode*> stk;
    stk.push(root);
    int inorderIndex = inorder.size() - 1;
    for(int i = postorder.size() - 2; i >= 0; i--)
    {
        auto node = stk.top();
        if(node->val != inorder[inorderIndex])
        {
            node->right = new TreeNode(postorder[i]);
            stk.push(node->right);
        }
        else
        {
            while(!stk.empty() && stk.top()->val == inorder[inorderIndex])
            {
                node = stk.top();
                stk.pop();
                inorderIndex--;
            }
            node->left = new TreeNode(postorder[i]);
            stk.push(node->left);
        }
    }
    return root;
}
//O(n) using recursion
unordered_map<int, int> index;
TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int postorder_left, int postorder_right, int inorder_left, int inorder_right)
{
    if(postorder_left > postorder_right)
        return nullptr;
    TreeNode* root = new TreeNode(postorder[postorder_right]);
    int inorderRootIndex = index[root->val];
    int right_subtree_size = inorder_right - inorderRootIndex;
    root->right = myBuildTree(inorder, postorder, postorder_right - right_subtree_size, postorder_right - 1, inorderRootIndex + 1, inorder_right);
    root->left = myBuildTree(inorder, postorder, postorder_left, postorder_right - right_subtree_size - 1, inorder_left, inorderRootIndex - 1);
    return root;
}
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder)
{
    for(int i = postorder.size()-1; i >= 0; i--)
    {
        index[inorder[i]] = i;
    }
    return myBuildTree(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
}