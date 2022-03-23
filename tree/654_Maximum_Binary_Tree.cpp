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
// recursion
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        TreeNode* res = build(nums, 0, nums.size() - 1);
        return res;
    }
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        int maxIndex = INT_MIN;
        int maxValue = INT_MIN;
        for(int i = left; i <= right; i++){
            maxIndex = nums[i] > maxValue ? i : maxIndex;
            maxValue = nums[i] > maxValue ? nums[i] : maxValue;
        }
        TreeNode* node = new TreeNode(maxValue);
        node->left = build(nums, left, maxIndex - 1);
        node->right = build(nums, maxIndex + 1, right);
        return node;
    }
};

// 2022.03.23
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        TreeNode* root = build(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        int maxValue = INT_MIN;
        int maxIndex = INT_MIN;
        for(int i = left; i <= right; i++){
            // first give value to index, or the maxValue will change
            maxIndex = nums[i] > maxValue ? i : maxIndex;
            maxValue = nums[i] > maxValue ? nums[i] : maxValue;
        }
        TreeNode* node = new TreeNode(maxValue);
        node->left = build(nums, left, maxIndex - 1);
        node->right = build(nums, maxIndex + 1, right);
        return node;
    }
};