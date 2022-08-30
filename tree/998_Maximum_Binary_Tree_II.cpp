// 2022.08.30
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while(cur && cur->val > val) {
            prev = cur;
            cur = cur->right;
        }
        if(prev == nullptr) {
            node->left = root;
            return node;
        }
        TreeNode* temp = prev->right;
        prev->right = node;
        node->left = temp;
        return root;
    }
};