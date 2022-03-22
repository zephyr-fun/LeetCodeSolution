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
// general solution, not only for BST, any order works
class Solution {
public:
    void traversal(TreeNode* node, unordered_map<int, int>& map){
        if(node == nullptr){
            return ;
        }
        map[node->val]++;
        traversal(node->left, map);
        traversal(node->right, map);
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        unordered_map<int, int> map;
        traversal(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        res.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i].second == vec[0].second){
                res.push_back(vec[i].first);
            }
            else{
                break; // early stop
            }
        }
        return res;
    }
};

// for BST, inorder traversal, recursion
class Solution {
public:
    int maxCount; // max history
    int count; // current
    TreeNode* pre;
    vector<int> res;
    void BST_traversal(TreeNode* node){
        if(node == nullptr){
            return ;
        }

        BST_traversal(node->left);

        if(pre == nullptr){
            count = 1;
        }
        else if(pre->val == node->val){
            count++;
        }
        else{
            count = 1;
        }
        pre = node;

        if(count == maxCount){
            result.push_back(node->val);
        }
        if(count > maxCount){
            result.clear();
            maxCount = count;
            result.push_back(node->val);
        }
        BST_traversal(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr){
            return res;
        }
        maxCount = 0;
        count = 0;
        pre = nullptr;
        res.clear();
        BST_traversal(root);    
        return res;
    }
};

// for BST, inorder traversal, non recursion
class Solution {
public:
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        int maxCount = 0; // max history
        int count = 0; // current
        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        // inorder traversal
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                if(pre == nullptr){
                    count = 1;
                }
                else if(pre->val == cur->val){
                    count++;
                }
                else{
                    count = 1;
                }
                if(count == maxCount){
                    res.push_back(cur->val);
                }
                if(count > maxCount){
                    res.clear();
                    res.push_back(cur->val);
                    maxCount = count;
                }
                pre = cur;// turn right
                cur = cur->right;
            }
        }
        return res;
    }
};