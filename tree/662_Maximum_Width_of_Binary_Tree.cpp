// 2022.08.27
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
typedef unsigned long long ULL;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, ULL>> que;
        que.push({root, 0});
        int res = 1;
        while(!que.empty()) {
            int size = que.size();
            ULL left = ULONG_LONG_MAX;
            ULL right = 0;
            for(int i = 0; i < size; i++) {
                auto [cur, cnt] = que.front();
                que.pop();
                if(cur->left != nullptr) {
                    que.push({cur->left, 2 * cnt + 1});
                    left = min(left, 2 * cnt + 1);
                    right = max(right, 2 * cnt + 1);
                }
                if(cur->right != nullptr) {
                    que.push({cur->right, 2 * cnt + 2});
                    left = min(left, 2 * cnt + 2);
                    right = max(right, 2 * cnt + 2);
                }
            }
            if(right >= left) {
                res = max(res, int(right - left + 1));
            }
        }
        return res;
    }
};