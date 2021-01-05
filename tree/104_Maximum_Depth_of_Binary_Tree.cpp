/*** 
 * Author: zephyr
 * Date: 2020-12-05 09:18:40
 * LastEditors: zephyr
 * LastEditTime: 2021-01-05 18:22:57
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
        for(int i = 1; i <= levelSize; i++)
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
}