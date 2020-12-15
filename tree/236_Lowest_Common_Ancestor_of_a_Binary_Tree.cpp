/*** 
 * Author: zephyr
 * Date: 2020-12-15 17:56:55
 * LastEditors: zephyr
 * LastEditTime: 2020-12-15 18:45:34
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\236_Lowest_Common_Ancestor_of_a_Binary_Tree.cpp
 */
#include <iostream>
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
// recursion
TreeNode* res;
bool judge(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root)
        return false;
    bool lson = judge(root->left, p, q);
    bool rson = judge(root->right, p, q);
    if(lson && rson || (root->val == p->val || root->val == q->val) && (lson || rson))
    {
        res = root;
    }
    return lson || rson || root->val == p->val || root->val == q->val;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    judge(root, p, q);
    return res;
}

//unordered_map
class Solution {
public:
unordered_map<int, TreeNode*> parent;
unordered_map<int, bool> record;
void buildParent(TreeNode* root)
{
    if(root->left)
    {
        parent[root->left->val] = root;
        buildParent(root->left);
    }
    if(root->right)
    {
        parent[root->right->val] = root;
        buildParent(root->right);
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    parent[root->val] = nullptr;
    buildParent(root);
    while(p != nullptr)
    {
        record[p->val] = true;
        p = parent[p->val];
    }
    while(q != nullptr)
    {
        if(record[q->val])
            return q;
        q = parent[q->val];
    }
    return nullptr;
}