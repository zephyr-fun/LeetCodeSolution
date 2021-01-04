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