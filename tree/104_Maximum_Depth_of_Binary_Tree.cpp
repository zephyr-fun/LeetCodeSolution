/*** 
 * Author: zephyr
 * Date: 2020-12-05 09:18:40
 * LastEditors: zephyr
 * LastEditTime: 2021-01-05 18:30:28
 * FilePath: \tree\104_Maximum_Depth_of_Binary_Tree.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//recursion
int maxDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//non recursion
int maxDepth2(TreeNode* root)
{
    if(!root)
        return 0;
    queue<TreeNode*> q;
    int level = 0;
    q.push(root);
    while(!q.empty())
    {
        int levelSize = q.size();
        for(int i = 1; i <= levelSize; i++) // note that we count by floor
        {
            auto node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        level += 1; 
    }
    return level;
};

// 2022.03.17
// level traversal solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxdepth = 0;
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            maxdepth += 1;
        }
        return maxdepth;
    }
};

// recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

// 2022.03.18
// recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        // postorder traversal
        return max(left, right) + 1;
    }
};

// backtrack
class Solution {
public:
    int res;
    int maxDepth(TreeNode* root) {
        res = 0;
        if(root == nullptr) return res;
        getDepth(root, 1);
        return res;
    }
    void getDepth(TreeNode* root, int depth){
        // preorder traversal
        res = depth > res ? depth : res;

        if(root == nullptr) return;
        if(root->left != nullptr){
            depth++;
            getDepth(root->left, depth);
            depth--;
        }
        if(root->right != nullptr){
            depth++;
            getDepth(root->right, depth);
            depth--;
        }
    }
};

// 2022.04.26
// recursion
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

// non recursion
class Solution {
public:
    int res;
    int maxDepth(TreeNode* root) {
        res = 0;
        if(root == nullptr) {
            return 0;
        }
        getDepth(root, 1);
        return res;
    }
    void getDepth(TreeNode* root, int depth) {
        res = res > depth ? res : depth;
        if(root->left != nullptr) {
            depth++;
            getDepth(root->left, depth);
            depth--;
        }
        if(root->right != nullptr) {
            depth++;
            getDepth(root->right, depth);
            depth--;
        }
    }
};

// 2022.11.13
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int depth) {
        if(root == nullptr) {
            return ;
        }
        res = max(res, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};