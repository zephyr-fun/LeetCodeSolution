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
    unordered_map<int, int> post_index;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < preorder.size(); i++){
            post_index[postorder[i]] = i;
        }
        TreeNode* root = subConstructPP(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }
    TreeNode* subConstructPP(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd){
        if(preStart > preEnd){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preStart]);
        int length = 0;
        if(preStart + 1 < preEnd){
            length = post_index[preorder[preStart + 1]] - postStart;
        }
        node->left = subConstructPP(preorder, preStart + 1, preStart + 1 + length < preEnd ? preStart + 1 + length : preEnd, postorder, postStart, postStart + length);
        node->right = subConstructPP(preorder, preStart + 1 + length + 1, preEnd, postorder, postStart + length + 1, postEnd - 1);
        
        return node;
    }
};
// 2022.03.23
class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        for(int i = 0; i < postorder.size(); i++){
            index[postorder[i]] = i;
        }
        TreeNode* res = subConstructPP(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
        return res;
    }
    TreeNode* subConstructPP(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd){
        if(preStart > preEnd){
            return nullptr;
        }
        // extra situation
        if(preStart == preEnd){
            return new TreeNode(preorder[preStart]);
        }
        
        TreeNode* node = new TreeNode(preorder[preStart]);
        int leftLength = index[preorder[preStart + 1]] - postStart + 1;
        node->left = subConstructPP(preorder, preStart + 1, preStart + leftLength, postorder, postStart, index[preorder[preStart + 1]]);
        node->right = subConstructPP(preorder, preStart + leftLength + 1, preEnd, postorder, index[preorder[preStart + 1]] + 1, postEnd - 1);
        return node;
    }
};