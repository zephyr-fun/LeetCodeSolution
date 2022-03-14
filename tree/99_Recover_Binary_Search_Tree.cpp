/*** 
 * Author: zephyr
 * Date: 2020-12-31 10:44:52
 * LastEditors: zephyr
 * LastEditTime: 2021-01-03 09:33:58
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
vector<int> res;// store inorder traversal result
void inorder(TreeNode* root)// inorder traversal in recursion way
{
    if(!root)
        return ;
    inorder(root->left);
    res.emplace_back(root->val);// add root->val into res
    inorder(root->right);
}
void inorder(TreeNode* root)// inorder traversal in non recursion way
{
    stack<TreeNode*> stk;
    while(!stk.empty() || root != nullptr)
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.emplace_back(root->val);
        root = root->right;
    }
}
pair<int, int> findswap(vector<int>& num)// find out the right position for swap
{
    int x = -1;
    int y = -1;
    for(int i = 0; i < num.size() - 1; i++)// at least 1 group, at most 2 gruops
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
            if(--count == 0)// early stop save time
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

// way 2 with hidden vector, that is we dont need res anymore, instead we use just a TreeNode* pred
void recoverTree(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* pred = nullptr;

    while(!stk.empty() || root != nullptr)// inorder traversal
    {
        while(root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(pred != nullptr && root->val < pred->val)// find out the mis order position
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

// way 3 with space : O(1)
void recoverTree(TreeNode* root)
{
    TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;
    
    while (root != nullptr) 
    {
        if (root->left != nullptr) 
        {
            // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
            predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root) 
            {
                predecessor = predecessor->right;
            }
            
            // 让 predecessor 的右指针指向 root，继续遍历左子树
            if (predecessor->right == nullptr) 
            {
                predecessor->right = root;
                root = root->left;
            }
            // 说明左子树已经访问完了，我们需要断开链接
            else 
            {
                if (pred != nullptr && root->val < pred->val) 
                {
                    y = root;
                    if (x == nullptr) 
                    {
                        x = pred;
                    }
                }
                pred = root;

                predecessor->right = nullptr;
                root = root->right;
            }
        }
        // 如果没有左孩子，则直接访问右孩子
        else 
        {
            if (pred != nullptr && root->val < pred->val) 
            {
                y = root;
                if (x == nullptr) 
                {
                    x = pred;
                }
            }
            pred = root;
            root = root->right;
        }
    }
    swap(x->val, y->val);
}

// 2022.03.14
// inorder traversal for BST means that the results will in a single order
// make this solution based on "Morris traversal"
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre = new TreeNode(INT_MIN);
        bool firstTime = true;
        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode* temp = root->left;
                while(temp->right != nullptr && temp->right != root){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    temp->right = root;//build a bridge, first time visit this node
                    root = root->left;
                }
                else{
                    temp->right = nullptr;//remove that bridge, second time visit this node
                    //inorder traversal
                    if(pre->val > root->val && firstTime){
                        first = pre;
                        firstTime = false;
                    }
                    if(pre->val > root->val && !firstTime){
                        second = root;
                    }
                    pre = root;
                    root = root->right;
                }
            }
            else{
                //inorder traversal
                if(pre->val > root->val && firstTime){
                    first = pre;
                    firstTime = false;
                }
                if(pre->val > root->val && !firstTime){
                    second = root;
                }
                pre = root;
                root = root->right;
            }
        }
        if(first != nullptr && second != nullptr){
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};