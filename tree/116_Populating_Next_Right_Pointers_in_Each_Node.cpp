/*** 
 * Author: zephyr
 * Date: 2020-12-17 09:16:55
 * LastEditors: zephyr
 * LastEditTime: 2020-12-17 09:37:38
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\116_Populating_Next_Right_Pointers_in_Each_Node.cpp
 */
#include <iostream>
#include <queue>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// BFS level traversal
Node* connect(Node* root) 
{
    if(!root)
        return nullptr;
    queue<Node*> q_node;
    q_node.push(root);
    while(!q_node.empty())
    {
        int levelSize = q_node.size();
        for(int i = 0; i < levelSize; i++)
        {
            auto node = q_node.front();
            q_node.pop();
            if(i < levelSize-1)
            {
                node->next = q_node.front();
            }
            if(node->left)
                q_node.push(node->left);
            if(node->right)
                q_node.push(node->right);
        }
    }
    return root;
}
//time:O(n)&space:O(1)
Node* connect2(Node* root)
{
    if(!root)
        return nullptr;
    Node* leftmost = root;
    while(leftmost->left)
    {
        Node* node = leftmost;
        while(node)
        {
            //connection type 1
            node->left->next = node->right;
            //connection type 2
            if(node->next)
                node->right->next = node->next->left;
            //move ptr
            node = node->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}

// 2022.03.16
class Solution {
public:
    Node* connect(Node* root){
        if(root == nullptr){
            return root;
        }
        Node* mostLeft = root;
        while(mostLeft->left != nullptr){
            Node* node = mostLeft;
            while(node != nullptr){
                node->left->next = node->right;
                if(node->next != nullptr){
                    node->right->next = node->next->left;
                }
                node = node->next;
            }
            mostLeft = mostLeft->left;
        }
        return root;
    }
};