// 2022.07.25
// plain 
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
class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* r) {
        root = r;
    }
    
    int insert(int val) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            res = cur->val;
            if(cur->left == nullptr) {
                cur->left = new TreeNode(val);
                break;
            }
            else {
                que.push(cur->left);
            }
            if(cur->right == nullptr) {
                cur->right = new TreeNode(val);
                break;
            }
            else {
                que.push(cur->right);
            }
        }
        return res;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */