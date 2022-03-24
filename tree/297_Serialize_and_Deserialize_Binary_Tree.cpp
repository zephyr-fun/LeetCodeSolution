/*** 
 * Author: zephyr
 * Date: 2020-12-16 15:57:56
 * LastEditors: zephyr
 * LastEditTime: 2020-12-16 16:14:25
 * FilePath: \tree\297.cpp
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
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
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Encodes a tree to a single string, with level traversal manner
string serialize(TreeNode* root)
{
    if(!root)
        return "";
    ostringstream out;
    queue<TreeNode*> q_node;
    q_node.push(root);
    while(!q_node.empty())
    {
        auto node = q_node.front();
        q_node.pop();
        if(node)
        {
            out << node->val << " ";
            q_node.push(node->left);
            q_node.push(node->right);
        }
        else
        {
            out << "null ";
        }
    }
    return out.str();
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
    if(data.empty())
        return nullptr;
    istringstream rebuild(data);
    string info;
    vector<TreeNode*> res;
    while(rebuild >> info)
    {
        if(info == "null")
            res.emplace_back(nullptr);
        else
        {
            res.emplace_back(new TreeNode(stoi(info)));
        }
    }
    int pos = 1;
    for(int i = 0; i < res.size() && pos < res.size(); i++)
    {
        if(res[i] == nullptr)
            continue;
        res[i]->left = res[pos++];
        if(pos < res.size())
            res[i]->right = res[pos++];
        
    }
    return res[0];
}
// 2022.03.24
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
    if(!root)
        return "";
    ostringstream out; // ostringstream
    queue<TreeNode*> q_node; // use a queue to perform level traversal
    q_node.push(root);
    while(!q_node.empty())
    {
        TreeNode* node = q_node.front();
        q_node.pop();
        if(node != nullptr)
        {
            out << node->val << " ";
            q_node.push(node->left);
            q_node.push(node->right);
        }
        else
        {
            out << "null ";
        }
    }
    // cout << out.str();
    return out.str();
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
    if(data.empty())
        return nullptr;
    istringstream rebuild(data); // istringstream
    string info;
    vector<TreeNode*> res;
    // convert to vector<TreeNode*>
    while(rebuild >> info)
    {
        // cout << info;
        if(info == "null")
            res.emplace_back(nullptr);
        else
        {
            res.emplace_back(new TreeNode(stoi(info)));
        }
    }
    // use position to control sub tree
    int pos = 1;
    for(int i = 0; pos < res.size(); i++)// no need for i < res.size(), cause pos will cross the bound first
    {
        if(res[i] == nullptr){
            // cout << "current i:" << i;
            continue;
        }      
        // cout << res[i] << "resi, respos" << res[pos];
        res[i]->left = res[pos++];
        if(pos < res.size())
            res[i]->right = res[pos++];
        
    }
    return res[0];
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));