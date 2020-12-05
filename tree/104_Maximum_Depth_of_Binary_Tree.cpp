/*** 
 * Author: zephyr
 * Date: 2020-12-05 09:18:40
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 09:43:56
 * FilePath: \LeetCodeSolution\tree\104_Maximum_Depth_of_Binary_Tree.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
int maxDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
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