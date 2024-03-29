/*** 
 * Author: zephyr
 * Date: 2020-12-22 15:24:45
 * LastEditors: zephyr
 * LastEditTime: 2020-12-22 15:27:07
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\429_N-ary_Tree_Level_Order_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    queue<Node*> qnode;
    if(!root)
        return res;
    qnode.push(root);
    while(!qnode.empty())
    {
        int size = qnode.size();
        vector<int> temp;
        for(int i = 0; i < size; i++)
        {
            auto node = qnode.front();
            qnode.pop();
            temp.emplace_back(node->val);
            for(auto c : node->children)
            {
                if(!c)
                    continue;
                qnode.push(c);
            }
        }
        res.emplace_back(temp);
    }
    return res;
}

// 2022.03.16
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);
                for(auto child : node->children){
                    if(child != nullptr){
                        que.push(child);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

// 2022.04.26
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);
                for(auto child : node->children) {
                    if(child != nullptr) {
                        que.push(child);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};