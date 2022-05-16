// 2022.05.16
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* cur = root;
        TreeNode* res = nullptr;
        while(cur != nullptr) {
            if(cur->val > p->val) {
                res = cur;
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return res;
    }
};