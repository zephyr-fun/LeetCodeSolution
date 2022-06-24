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
// 2022.03.16
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->val > levelMax){
                    levelMax = node->val;
                }
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            res.push_back(levelMax);
        }
        return res;
    }
};

// 2022.04.26
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                levelMax = levelMax > node->val ? levelMax : node->val;
                if(node->left != nullptr) {
                    que.push(node->left);
                }
                if(node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(levelMax);
        }
        return res;
    }
};

// 2022.06.24
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            int maxVal = INT_MIN; // note that -0x3f3f3f3f > some examples
            for(int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                maxVal = max(maxVal, cur->val);
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            res.emplace_back(maxVal);
        }
        return res;
    }
};