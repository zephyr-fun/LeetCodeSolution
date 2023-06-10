// 2022.07.29
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
    map<int, map<int, vector<int>>> map; // col, row
    void dfs(TreeNode* root, int row, int col) {
        if(root == nullptr) {
            return ;
        }
        map[col][row].emplace_back(root->val);
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(auto [ck, cv] : map) {
            vector<int> temp;
            for(auto [rk, rv] : cv) {
                sort(rv.begin(), rv.end());
                for(auto it : rv) {
                    temp.emplace_back(it);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

// 2022.09.06
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int mod = 1000;
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> temp;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, mod));
        int row = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [cur, col] = que.front();
                que.pop();
                temp[col][row].emplace_back(cur->val);
                if(cur->left != nullptr) {
                    que.push(make_pair(cur->left, col - 1));
                }
                if(cur->right != nullptr) {
                    que.push(make_pair(cur->right, col + 1));
                }
            }
            row++;
        }
        for(auto [c, t] : temp) {
            vector<int> combine;
            for(auto [r, v] : t) {
                sort(v.begin(), v.end());
                for(auto it : v) {
                    combine.emplace_back(it);
                }
            }
            res.emplace_back(combine);
        }
        return res;
    }
};

// 2022.09.24
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int offset = 1000;
        map<int, map<int, vector<int>>> temp;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        int row = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [cur, col] = que.front();
                que.pop();
                temp[col + offset][row].emplace_back(cur->val);
                if(cur->left) {
                    que.push(make_pair(cur->left, col - 1));
                }
                if(cur->right) {
                    que.push(make_pair(cur->right, col + 1));
                }
            }
            row++;
        }
        vector<vector<int>> res;
        for(auto& [c, t] : temp) {
            vector<int> combine;
            for(auto& [r, v] : t) {
                sort(v.begin(), v.end());
                for(auto& it : v) {
                    combine.emplace_back(it);
                }
            }
            res.emplace_back(combine);
        }
        return res;
    }
};

// 2023.03.25
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
    map<int, map<int, multiset<int>>> map;
    void traversal(TreeNode* cur, int row, int col) {
        if(cur == nullptr) {
            return ;
        }
        map[row][col].insert(cur->val);
        traversal(cur->left, row - 1, col + 1);
        traversal(cur->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root, 0, 0);
        vector<vector<int>> res;
        for(auto& [k, v] : map) {
            vector<int> temp;
            for(auto& [kk, vv] : v) {
                for(auto& it : vv) {
                    temp.emplace_back(it);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

// 2023.06.10
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
    map<int, map<int, multiset<int>>> map;

    void traversal(TreeNode* root, int row, int col) {
        if(root == nullptr) {
            return ;
        }
        map[col][row].insert(root->val);
        traversal(root->left, row + 1, col - 1);
        traversal(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root, 0, 0);
        vector<vector<int>> res;
        for(auto&[k, v] : map) {
            vector<int> temp;
            for(auto&[kk, vv] : v) {
                vector<int> seg(vv.begin(), vv.end());
                temp.insert(temp.end(), seg.begin(), seg.end());
            }
            res.emplace_back(temp);
        }
        return res;
    }
};