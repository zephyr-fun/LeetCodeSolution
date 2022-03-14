/*** 
 * Author: zephyr
 * Date: 2020-12-10 16:15:56
 * LastEditors: zephyr
 * LastEditTime: 2021-01-07 21:43:48
 * FilePath: \tree\105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> index;

// preorder and inorder have features
TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right) {
        return nullptr;
    }
    
    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];
    
    // 先把根节点建立出来
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
}

// second way
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(!preorder.size())
        return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    int inorderIndex = 0;
    stack<TreeNode*> stk;
    stk.push(root);
    for(int i = 1; i < preorder.size(); i++)
    {
        TreeNode* node = stk.top();
        if(node->val != inorder[inorderIndex])
        {
            node->left = new TreeNode(preorder[i]);
            stk.push(node->left);
        }
        else
        {
            while(!stk.empty() && stk.top()->val == inorder[inorderIndex])
            {
                node = stk.top();
                stk.pop();
                inorderIndex++;
            }
            node->right = new TreeNode(preorder[i]);
            stk.push(node->right);
        }
    }
    return root;
}

// 2nd
// way 1
TreeNode* buildMyTree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright)
{
    if(preleft > preright)
        return nullptr;
    TreeNode* root = new TreeNode(preorder[preleft]);
    int inorderroot = index[preorder[preleft]];
    int sublefttree = inorderroot - inleft;
    root->left = buildMyTree(preorder, inorder, preleft + 1, preleft + sublefttree, inleft, inorderroot - 1);
    root->right = buildMyTree(preorder, inorder, preleft + sublefttree + 1, preright, inorderroot + 1, inright);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for(int i = 0; i < inorder.size(); i++)
    {
        index[inorder[i]] = i;
    }
    return buildMyTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

// way 2
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(!preorder.size())
        return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    int inorderindex = 0;
    stack<TreeNode*> stk;
    stk.push(root);
    for(int i = 1; i < preorder.size(); i++)
    {
        auto node = stk.top();
        if(node->val != inorder[inorderindex])
        {
            node->left = new TreeNode(preorder[i]);
            stk.push(node->left);
        }
        else
        {
            while(!stk.empty() && stk.top()->val == inorder[inorderindex]) // you need to know that the stk.top() is the next
            {
                node = stk.top();
                stk.pop();
                inorderindex++;
            }
            node->right = new TreeNode(preorder[i]);
            stk.push(node->right);
        }
    }
    return root;
}

// 2022.03.14
class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        if(preStart > preEnd){
            return ;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);// preorder traversal
        root->left = build(preorder, preStart + 1, preStart + index[preorder[preStart]] - inStart, inorder, inStart, index[preorder[preStart]] - 1);
        root->right = build(preorder, preStart + index[preorder[preStart]] - inStart + 1, preEnd, inorder, index[preorder[preStart]] + 1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for(int i = 0; i < size; i++) {
            index[inorder[i]] = i;
        }
        TreeNode* res = build(preorder, 0, size - 1, inorder, 0, size - 1);
        return res;
    }
};