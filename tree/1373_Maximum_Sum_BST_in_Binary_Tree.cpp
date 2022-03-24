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
// 2022.03.24
// non compress, overtime
class Solution {
public:
    TreeNode* pre;
    int maxValue = INT_MIN;
    TreeNode* maxNode = nullptr;
    int maxSumBST(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        helper(root);
        return maxValue > 0 ? maxValue : 0;
    }
    void helper(TreeNode* node){
        if(node == nullptr){
            return;
        }
        helper(node->left);
        pre = nullptr;
        helper(node->right);
        pre = nullptr;
        if(validateBST(node)){
            int sum = sumBST(node);
            maxValue = maxValue > sum ? maxValue : sum;
        }
        pre = nullptr;
    }
    bool validateBST(TreeNode* node){
        if(node == nullptr){
            return true;
        }
        bool left = validateBST(node->left);
        if(pre != nullptr && pre->val >= node->val){
            return false;
        }
        pre = node;
        bool right = validateBST(node->right);
        return left && right;
    }
    int sumBST(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left = sumBST(node->left);
        int right = sumBST(node->right);
        return left + right + node->val;
    }
};

// State Compression
class Solution {
public:
    int maxValue = INT_MIN;
    int maxSumBST(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root);
        return maxValue;
    }
    vector<int> dfs(TreeNode* node){
        if(node == nullptr){
            return {true, INT_MAX, INT_MIN, 0};
        }
        auto Larr = dfs(node->left);
        auto Rarr = dfs(node->right);
        int sum = 0, curmin, curmax;
        if(Larr[0] == false || Rarr[0] == false || node->val <= Larr[2] || node->val >= Rarr[1]){
            return {false, 0, 0, 0};
        }
        curmin = node->left ? Larr[1] : node->val;
        curmax = node->right ? Rarr[2] : node->val;
        sum += Larr[3] + Rarr[3] + node->val;
        maxValue = max(sum, maxValue);
        return {true, curmin, curmax, sum};
    }
};
// find difference
class Solution {
public:
    bool isBST(TreeNode* root,int mini,int maxi){
        if(root==nullptr){
            return true;
        }
        int val=root->val;
        return (val>mini&&val<maxi&&isBST(root->left,mini,val)&&isBST(root->right,val,maxi));
    }
    int res=0;
    int sumBST(TreeNode* root){
        if(root==nullptr)  return 0;
        int sum=root->val+sumBST(root->left)+sumBST(root->right);
        res=max(res,sum);
        return sum;
    }
    void DFS(TreeNode* root){
        if(isBST(root,INT_MIN,INT_MAX)){
            sumBST(root);
            return ;
        }
        DFS(root->right);
        DFS(root->left);
    }
    int maxSumBST(TreeNode* root) {
        DFS(root);
        return res;
    }
};