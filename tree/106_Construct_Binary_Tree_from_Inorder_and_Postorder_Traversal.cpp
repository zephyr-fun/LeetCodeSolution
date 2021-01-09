/*** 
 * Author: zephyr
 * Date: 2020-12-12 14:56:36
 * LastEditors: zephyr
 * LastEditTime: 2021-01-09 11:15:34
 * FilePath: \tree\106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    for(int i = postorder.size()-1; i >= 0; i--)
    {
        index[inorder[i]] = i;
    }
    return myBuildTree(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
}

// 2nd
// way 1 recursion
unordered_map<int, int> index;
TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int postorder_left, int postorder_right, int inorder_left, int inorder_right)
{
    if(postorder_left > postorder_right)
        return nullptr;
    int inorder_root = index[postorder[postorder_right]];// postorder_right是索引，记得先用索引取值
    int subrighttree = inorder_right - inorder_root;// 右边界减去根节点的值等于右子树长度
    TreeNode* root = new TreeNode(postorder[postorder_right]);
    root->right = myBuildTree(inorder, postorder, postorder_right - subrighttree, postorder_right - 1, inorder_root + 1, inorder_right);
    root->left = myBuildTree(inorder, postorder, postorder_left, postorder_right - subrighttree - 1, inorder_left, inorder_root - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    if(!postorder.size())
        return nullptr;
    for(int i = postorder.size() - 1; i >= 0; i--)//记录的是从当前根节点出发能到达的最远右子树节点
    {
        index[inorder[i]] = i;
    }
    return myBuildTree(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
}

// way 2 non recursion
