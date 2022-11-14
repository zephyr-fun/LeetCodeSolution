// 2022.11.14
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
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int cur = preorder[left];
        TreeNode* res = new TreeNode(cur);
        int idx = right + 1;
        for(int i = left + 1; i <= right; i++) {
            if(preorder[i] > cur) {
                idx = i;
                break;
            }
        }
        res->left = build(preorder, left + 1, idx - 1);
        res->right = build(preorder, idx, right);
        return res;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};