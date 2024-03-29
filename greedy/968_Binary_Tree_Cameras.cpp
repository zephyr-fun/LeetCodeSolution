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

// 2022.04.07
class Solution {
public:
    int res = 0;
    int traversal(TreeNode* cur){
        if(cur == nullptr){
            return 2; //covered
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if(left == 2 && right == 2){
            return 0;//uncovered
        }
        if(left == 0 || right == 0){
            res++;
            return 1;//camera
        }
        if(left == 1 || right == 1){
            return 2;//covered
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(traversal(root) == 0){
            res++;
        }
        return res;
    }
};

// 2022.06.19
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
// 0 for no cover, 1 for with cam, 2 for with cover
class Solution {
public:
    int res = 0;
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 2;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if(left == 2 && right == 2) {
            return 0;
        }
        else if(left == 0 || right == 0) {
            res++;
            return 1;
        }
        else if(left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int rootStatus = traversal(root);
        if(!rootStatus) {
            res++;
        }
        return res;
    }
};