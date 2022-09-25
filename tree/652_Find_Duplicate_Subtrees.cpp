/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 2022.03.23
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> map;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == nullptr){
            return res;
        }
        string temp = helper(root);
        return res;
    }
    string helper(TreeNode* node){
        if(node == nullptr){
            return "#";
        }
        string left = helper(node->left);
        string right = helper(node->right);
        string cur = left + "," + right + "," + to_string(node->val);
        map[cur]++;
        if(map[cur] == 2){
            res.push_back(node);
        }
        return cur;
    }
};

// 2022.09.05
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int p = 131;
    // int q = 13131;
    unordered_map<string, int> map;
    vector<TreeNode*> res;
    string traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return "#";
        }
        string left = traversal(cur->left);
        string right = traversal(cur->right);
        string temp = left + "," + right + "," + to_string(cur->val);
        map[temp]++;
        if(map[temp] == 2) {
            res.emplace_back(cur);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res;
    }
};