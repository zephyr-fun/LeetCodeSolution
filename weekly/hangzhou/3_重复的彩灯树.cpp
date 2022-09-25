// 2022.09.25
// same as 652
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
    vector<TreeNode*> lightDistribution(TreeNode* root) {
        traversal(root);
        return res;
    }
};