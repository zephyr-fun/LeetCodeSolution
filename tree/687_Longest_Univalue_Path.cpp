// 2022.09.02
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
    unordered_map<int, int> map;
    pair<int, int> traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return {-1, 0};
        }
        auto [left, leftCnt] = traversal(cur->left);
        auto [right, rightCnt] = traversal(cur->right);
        int res = cur->val;
        int resCnt = 1;
        int ress = 0;
        if(res == left) {
            resCnt += leftCnt;
            ress = max(ress, leftCnt);
        }
        if(res == right) {
            resCnt += rightCnt;
            ress = max(ress, rightCnt);
        }
        // cout << res << ress + 1 << resCnt << left << leftCnt << right << rightCnt << endl;
        map[res] = max(map[res], resCnt);
        
        return {res, ress + 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        traversal(root);
        int res = 0;
        for(auto [k, v] : map) {
            res = max(res, v);
        }
        return res - 1;
    }
};