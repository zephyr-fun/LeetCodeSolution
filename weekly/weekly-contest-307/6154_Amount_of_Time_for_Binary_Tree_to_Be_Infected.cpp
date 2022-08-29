// 2022.08.29 sorted
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
    int n;
    vector<vector<int>> tree;
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 0;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        return left + right + 1;
    }
    void tl(TreeNode* cur) {
        if(cur->left) {
            tree[cur->val].emplace_back(cur->left->val);
            tree[cur->left->val].emplace_back(cur->val);
            tl(cur->left);
        }
        if(cur->right) {
            tree[cur->val].emplace_back(cur->right->val);
            tree[cur->right->val].emplace_back(cur->val);
            tl(cur->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        n = traversal(root);
        tree.resize(100007);
        tl(root);
        queue<int> que;
        unordered_set<int> set;
        que.push(start);
        int res = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                int parent = que.front();
                que.pop();
                set.insert(parent);
                for(auto num : tree[parent]) {
                    if(set.count(num)) {
                        continue;
                    }
                    que.push(num);
                }
            }
            res++;
        }
        return res - 1;
    }
};