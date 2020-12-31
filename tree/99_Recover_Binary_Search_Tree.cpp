/*** 
 * Author: zephyr
 * Date: 2020-12-31 10:44:52
 * LastEditors: zephyr
 * LastEditTime: 2020-12-31 11:40:22
 * FilePath: \tree\99_Recover_Binary_Search_Tree.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
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
// way 1 space : O(n)
vector<int> res;
void inorder(TreeNode* root)
{
    if(!root)
        return ;
    inorder(root->left);
    res.emplace_back(root->val);
    inorder(root->right);
}
pair<int, int> findswap(vector<int>& num)
{
    int x = -1;
    int y = -1;
    for(int i = 0; i < num.size() - 1; i++)
    {
        if(num[i+1] < num[i])
        {
            y = num[i+1];
            if(x == -1)
            {
                x = num[i];
            }
        }
    }
    return {x, y};
}
void recover(TreeNode* root, int count, int x, int y)
{
    if(root != nullptr)
    {
        if(root->val == x || root->val == y)
        {
            root->val = root->val == x ? y : x;
            if(--count == 0)
                return ;
        }
    
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }
}
void recoverTree(TreeNode* root) {
    inorder(root);
    pair<int, int> swapped =  findswap(res);
    recover(root, 2, swapped.first, swapped.second);
}

// way 2 with hidden vector
void recoverTree(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* pred = nullptr;

    while(!stk.empty() || root != nullptr)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(pred != nullptr && root->val < pred->val)
        {
            y = root;
            if(x == nullptr)
            {
                x = pred;
            }
            else
                break;
        }
        pred = root;
        root = root->right;
    }
    swap(x->val, y->val);
}