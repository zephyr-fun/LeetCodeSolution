/*** 
 * Author: zephyr
 * Date: 2020-12-17 10:05:59
 * LastEditors: zephyr
 * LastEditTime: 2020-12-17 10:07:39
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\117_Populating_Next_Right_Pointers_in_Each_Node_II.cpp
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
// BFS level size traversal
Node* connect(Node* root) {
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
                node->next = q_node.front();
            if(node->left)
                q_node.push(node->left);
            if(node->right)
                q_node.push(node->right);
        }
    }
    return root;
}