// 2022.09.25
// same as 968
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
    int res = 0;
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 2;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if(left == 2 && right == 2) {
            return 0;
        }
        if(left == 0 || right == 0) {
            res++;
            return 1;
        }
        if(left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
    int minSupplyStationNumber(TreeNode* root) {
        if(traversal(root) == 0) {
            res++;
        }
        return res;
    }
};