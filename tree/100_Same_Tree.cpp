/*** 
 * Author: zephyr
 * Date: 2020-11-28 20:34:56
 * LastEditors: zephyr
 * LastEditTime: 2021-01-03 09:41:33
 * FilePath: \tree\100_Same_Tree.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
// way 1 recursion
bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p == nullptr && q == nullptr)
        return true;
    else if(p == nullptr || q == nullptr)
        return false;
    else if(p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// way 2 non recursion
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == nullptr && q == nullptr)
        return true;
    else if(p == nullptr || q == nullptr)
        return false;
    queue<TreeNode*> queue1, queue2; // level traversal
    queue1.push(p);
    queue2.push(q);
    while(!queue1.empty() && !queue2.empty())
    {
        auto node1 = queue1.front();
        queue1.pop();
        auto node2 = queue2.front();
        queue2.pop();
        if(node1->val != node2->val)
            return false;
        auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;// kind of no need 
        if((left1 == nullptr) ^ (left2 == nullptr))
            return false;
        if((right1 == nullptr) ^ (right2 == nullptr))
            return false;
        if(left1 != nullptr)
            queue1.push(left1);
        if(right1 != nullptr)
            queue1.push(right1);
        if(left2 != nullptr)
            queue2.push(left2);
        if(right2 != nullptr)
            queue2.push(right2);
    }
    return queue1.empty() && queue2.empty();
}