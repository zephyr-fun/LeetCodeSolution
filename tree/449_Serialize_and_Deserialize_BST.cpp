/*** 
 * Author: zephyr
 * Date: 2021-01-01 10:14:13
 * LastEditors: zephyr
 * LastEditTime: 2021-01-01 10:17:00
 * FilePath: \SSTGCNNd:\GithubWorkSpace\LeetCodeSolution\tree\449_Serialize_and_Deserialize_BST.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root)
        return "";
    queue<TreeNode*> q_node;
    q_node.push(root);
    ostringstream output;
    while(!q_node.empty())
    {
        auto node = q_node.front();
        q_node.pop();
        if(node == nullptr)
            output << "null ";
        else
        {
            output << node->val << " ";
            q_node.push(node->left);
            q_node.push(node->right);
        }
    }
    return output.str();
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty())
        return nullptr;
    istringstream input(data);
    vector<TreeNode*> nodes;
    string val;
    while(input >> val)
    {
        if(val == "null")
            nodes.emplace_back(nullptr);
        else
        {
            nodes.emplace_back(new TreeNode(stoi(val)));
        }
    }
    int pos = 1;
    for(int i = 0; i < nodes.size(); i++)
    {
        if(nodes[i] == nullptr)
            continue;
        nodes[i]->left = nodes[pos++];
        nodes[i]->right = nodes[pos++];
    }
    return nodes[0];
}


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// 2022.05.11
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// using postorder traversal + BST feature
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(root == nullptr) {
            return res;
        }
        vector<int> arr;
        postOrderTraversal(root, arr);
        for(int i = 0; i < arr.size() - 1; i++) {
            res += to_string(arr[i]);
            res += ',';
        }
        res += to_string(arr[arr.size() - 1]);
        return res;
    }

    void postOrderTraversal(TreeNode* root, vector<int>& arr) {
        if(root == nullptr) {
            return ;
        }
        postOrderTraversal(root->left, arr);
        postOrderTraversal(root->right, arr);
        arr.push_back(root->val);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data;
        if(data.size() == 0) {
            return nullptr;
        }
        vector<int> arr;
        split(data, arr);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            // cout << arr[i];
            st.push(arr[i]);
        }
        TreeNode* res;
        res = construct(st, INT_MAX, INT_MIN);
        return res;
    }

    void split(string data, vector<int>& arr) {
        int left = 0;
        int right = 0;
        while(right < data.size()) {
            while(right < data.size() && data[right] != ',') {
                right++;
            }
            arr.push_back(stoi(data.substr(left, right - left)));
            while(right < data.size() && data[right] == ',') {
                right++;
            }
            left = right;
        }
    }

    TreeNode* construct(stack<int>& st, int upper, int lower) {
        if(st.size() == 0 || st.top() > upper || st.top() < lower) {
            return nullptr;
        }
        int val = st.top();
        // cout << val;
        st.pop();
        TreeNode* root = new TreeNode(val);
        // order matters
        root->right = construct(st, upper, val);
        root->left = construct(st, val, lower);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;