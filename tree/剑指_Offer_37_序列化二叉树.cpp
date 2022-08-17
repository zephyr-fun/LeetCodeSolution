// 2022.08.06
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if(cur != nullptr) {
                res += to_string(cur->val);
                res += " ";
                que.push(cur->left);
                que.push(cur->right);
            }
            else {
                res += "@";
                res += " ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        string p;
        iss >> p;
        if(p == "@") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(p));
        queue<TreeNode*> que;
        que.push(root);
        while(iss >> p) {
            TreeNode* cur = que.front();
            que.pop();
            if(p != "@") {
                cur->left = new TreeNode(stoi(p));
                que.push(cur->left);
            }
            if(iss >> p && p != "@") {
                cur->right = new TreeNode(stoi(p));
                que.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// 2022.08.17
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if(cur != nullptr) {
                res += to_string(cur->val);
                res += " ";
                que.push(cur->left);
                que.push(cur->right);
            }
            else {
                res += "@";
                res += " ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        string p;
        iss >> p;
        if(p == "@") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(p));
        queue<TreeNode*> que;
        que.push(root);
        while(iss >> p) {
            TreeNode* cur = que.front();
            que.pop();
            if(p != "@") {
                cur->left = new TreeNode(stoi(p));
                que.push(cur->left);
            }
            if(iss >> p && p != "@") {
                cur->right = new TreeNode(stoi(p));
                que.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));