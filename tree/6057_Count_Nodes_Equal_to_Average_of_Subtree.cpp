// 2022.05.08
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
    int res = 0;
    // pair<nodeNum, sum>
    pair<int, int> traversal(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) {
            res += 1;
            return {1, root->val};
        }
        int num = 1;
        int sum = root->val;
        if(root->left != nullptr) {
            pair<int, int> left = traversal(root->left);
            num += left.first;
            sum += left.second;
        }
        if(root->right != nullptr) {
            pair<int, int> right = traversal(root->right);
            num += right.first;
            sum += right.second;
        }
        if(root->val == sum / num) {
            res += 1;
        }
        return {num, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        traversal(root);
        return res;
    }
};