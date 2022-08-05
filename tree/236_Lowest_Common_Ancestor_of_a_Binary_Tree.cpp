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

// 2022.03.21
// recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// postorder traversal == backtrack
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        
        if(left != nullptr && right == nullptr) return left;
        else if(right != nullptr && left == nullptr) return right;
        else return nullptr; // right == nullptr && left == nullptr
    }
};

// 2022.04.30
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) {
            return root;
        }
        if(left == nullptr && right != nullptr) {
            return right;
        }
        else if(left != nullptr && right == nullptr) {
            return left;
        }
        else {
            return nullptr;
        }
    }
};

// 2022.08.05
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) {
            return root;
        }
        else if(left == nullptr && right != nullptr) {
            return right;
        }
        else if(left != nullptr && right == nullptr) {
            return left;
        }
        else {
            return nullptr;
        }
    }
};