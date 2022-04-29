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
// 2022.03.21
// recursion, reuse root1 as res
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr){
            return root2;
        }
        if(root2 == nullptr){
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// non recursion
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            node1->val = node1->val + node2->val;
            if(node1->left != nullptr && node2->left != nullptr){
                que.push(node1->left);
                que.push(node2->left);
            }
            if(node1->right != nullptr && node2->right != nullptr){
                que.push(node1->right);
                que.push(node2->right);
            }
            if(node1->left == nullptr){
                node1->left = node2->left;
            }
            if(node1->right == nullptr){
                node1->right = node2->right;
            }
        }
        return root1;
    }
};

// 2022.04.29
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        if(root1 == nullptr) {
            return root2;
        }
        if(root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};