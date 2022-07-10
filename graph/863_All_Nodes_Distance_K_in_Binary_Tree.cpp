// 2022.07.10
// which dosen't work
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> map;
        int layer = 0;
        int targetLayer = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int>& temp = map[layer];
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if(cur == target) {
                    targetLayer = layer;
                }
                else {
                    temp.emplace_back(cur->val);
                }
                if(cur->left != nullptr) {
                    que.push(cur->left);
                }
                if(cur->right != nullptr) {
                    que.push(cur->right);
                }
            }
            layer++;
        }
        vector<int> res;
        if(map.count(k - targetLayer)) {
            for(int i = 0; i < map[k - targetLayer].size(); i++) {
                res.emplace_back(map[k - targetLayer][i]);
            }
        }
        if(map.count(targetLayer - k)) {
            for(int i = 0; i < map[targetLayer - k].size(); i++) {
                res.emplace_back(map[targetLayer - k][i]);
            }
        }
        if(map.count(k + targetLayer)) {
            for(int i = 0; i < map[k + targetLayer].size(); i++) {
                res.emplace_back(map[k + targetLayer][i]);
            }
        }
        return res;
    }
};

// dfs + bfs
class Solution {
public:
    vector<int> res;
    int distance;
    TreeNode* tar;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) {
            return res;
        }
        if(k == 0) {
            return {target->val};
        }
        distance = k;
        tar = target;
        dfs(target, 0); // 遍历**target**子节点找出距离为K的节点
        target->left = nullptr;
        target->right = nullptr; //清空**target**节点的子节点
        if(root != target) {
            dfsFindNode(root); // 将剩下的二叉树转为以**target**节点为根节点的二叉树
            dfs(target,0); // 再次遍历**target**子节点找出距离为K的节点
        }
        return res;
    }

    // 回溯，回溯之前把子节点中包含target节点的子节点设为空，回溯之后把父节点放到这个空子节点中
    bool dfsFindNode(TreeNode* root) {
        if(!root) {
            return false;
        }
        if(root == tar) {
            return true;
        }
        if(dfsFindNode(root->left)) {
            if(!root->left->left) {
                root->left->left = root;
            }
            else if(!root->left->right) {
                root->left->right = root;
            }
            root->left = nullptr;
            return true;
        }
        if(dfsFindNode(root->right)) {
            if(!root->right->left) {
                root->right->left = root;
            }
            else if(!root->right->right) {
                root->right->right = root;
            }
            root->right = nullptr;
            return true;
        }
        return false;
    }

    void dfs(TreeNode* root, int step) {
        if(!root) {
            return;
        }
        if(step == distance) {
            res.push_back(root->val);
        }
        dfs(root->left,step+1);
        dfs(root->right,step+1);
    }
};

// build graph + dfs
// easy to understand version
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
    unordered_map<TreeNode*, vector<TreeNode*>> map;
    vector<int> res;
    void build(TreeNode* root) {
        if(root->left != nullptr) {
            map[root].emplace_back(root->left);
            map[root->left].emplace_back(root);
            build(root->left);
        }
        if(root->right != nullptr) {
            map[root].emplace_back(root->right);
            map[root->right].emplace_back(root);
            build(root->right);
        }
    }
    void find(TreeNode* cur, TreeNode* father, int rest) {
        if(rest == 0) {
            res.emplace_back(cur->val);
        }
        for(auto it : map[cur]) {
            if(it != father) {
                find(it, cur, rest - 1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        find(target, nullptr, k);
        return res;
    }
};