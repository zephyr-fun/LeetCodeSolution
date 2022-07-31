// 2022.07.31
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
    int maxLevelSum(TreeNode* root) {
        int max = -0x3f3f3f3f;
        set<int> set;
        int level = 1;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            int sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->val;
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            if(sum > max) {
                max = sum;
                set.clear();
                set.insert(level);
            }
            else if(sum == max) {
                set.insert(level);
            }
            level++;
        }
        return *set.begin();
    }
};