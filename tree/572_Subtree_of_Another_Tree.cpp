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
// 2022.03.19
// recursion
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        if(root != nullptr && subRoot == nullptr) return false;
        if(root == nullptr && subRoot != nullptr) return false;
        if(root->val != subRoot->val) return false;
        bool left = isSameTree(root->left, subRoot->left);
        bool right = isSameTree(root->right, subRoot->right);
        return left && right;
    }
    bool dfs(TreeNode* node, TreeNode* subNode){
        if(node == nullptr){
            return false;
        }
        return isSameTree(node, subNode) || dfs(node->left, subNode) || dfs(node->right, subNode);
    }
};

// kmp
class Solution {
public:
    vector <int> sOrder, tOrder;
    int maxElement, lNull, rNull;

    void getMaxElement(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        maxElement = max(maxElement, node->val);
        getMaxElement(node->left);
        getMaxElement(node->right);
    }

    void getDfsOrder(TreeNode* node, vector<int>& tar){
        // introduce lNull and rNull to make sure uniqueness
        if (node == nullptr) {
            return;
        }
        // preorder traversal
        tar.push_back(node->val);

        if (node->left) {
            getDfsOrder(node->left, tar);
        } else {
            tar.push_back(lNull);
        }
        if (node->right) {
            getDfsOrder(node->right, tar);
        } else {
            tar.push_back(rNull);
        }
    }

    bool kmp() {
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector <int> fail(tOrder.size(), 0);
        // construct next
        for (int i = 1, j = 0; i < tLen; ++i) {
            while (j > 0 && tOrder[i] != tOrder[j]) {
                j = fail[j - 1];
            }
            if (tOrder[i] == tOrder[j]) {
                ++j;
            }
            fail[i] = j;
        }
        // match text and pattern
        for (int i = 0, j = 0; i < sLen; ++i) {
            while (j > 0 && sOrder[i] != tOrder[j]) {
                j = fail[j - 1];
            }
            if (sOrder[i] == tOrder[j]) {
                ++j;
            }
            if (j == tLen) {
                return true;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        maxElement = INT_MIN;
        getMaxElement(s);
        getMaxElement(t);
        lNull = maxElement + 1;
        rNull = maxElement + 2;

        getDfsOrder(s, sOrder);
        getDfsOrder(t, tOrder);

        return kmp();
    }
};

// Tree hash
class Solution {
public:
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    //Euler sieve
    void getPrime() {
        vis[0] = vis[1] = 1; tot = 0;
        for (int i = 2; i < MAX_N; ++i) {
            if (!vis[i]) p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

    struct Status {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0) 
            : f(f_), s(s_) {}
    };

    unordered_map <TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right) return;
        if (o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v]: hS) {
            if (v.f == tHash) {
                return true;
            }
        } 

        return false;
    }
};


// 2022.04.27
// recursion
class Solution {
public:
    bool isSameTree(TreeNode* node, TreeNode* subNode) {
        if(node == nullptr && subNode == nullptr) {
            return true;
        }
        if(node == nullptr || subNode == nullptr || node->val != subNode->val) {
            return false;
        }
        return isSameTree(node->left, subNode->left) && isSameTree(node->right, subNode->right);
    }
    bool dfs(TreeNode* node, TreeNode* subRoot) {
        if(node == nullptr) {
            return false;
        }
        return isSameTree(node, subRoot) || dfs(node->left, subRoot) || dfs(node->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};

// kmp
class Solution {
public:
    int maxElement, lNull, rNull;
    vector<int> sOrder, tOrder;
    void getMaxElement(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }
        maxElement = max(root->val, maxElement);
        getMaxElement(root->left);
        getMaxElement(root->right);
    }
    void getPreorder(TreeNode* root, vector<int>& order) {
        if(root == nullptr) {
            return ;
        }
        order.push_back(root->val);
        if(root->left != nullptr) {
            getPreorder(root->left, order);
        }
        else {
            order.push_back(lNull);
        }
        if(root->right != nullptr) {
            getPreorder(root->right, order);
        }
        else {
            order.push_back(rNull);
        }
    }
    bool kmp() {
        int sLen = sOrder.size();
        int tLen = tOrder.size();
        vector<int> next(tLen, 0);
        for(int left = 0, right = 1; right < tLen; right++) {
            while(left > 0 && tOrder[left] != tOrder[right]) {
                left = next[left - 1];
            }
            if(tOrder[left] == tOrder[right]){
                left++;
            }
            next[right] = left;
        }
        for(int sIndex = 0, tIndex = 0; sIndex < sLen; sIndex++) {
            while(tIndex > 0 && sOrder[sIndex] != tOrder[tIndex]){
                tIndex = next[tIndex - 1];
            }
            if(sOrder[sIndex] == tOrder[tIndex]) {
                tIndex++;
            }
            if(tIndex == tLen) {
                return true;
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) {
            return false;
        }
        getMaxElement(root);
        getMaxElement(subRoot);
        lNull = maxElement + 1;
        rNull = maxElement + 2;
        getPreorder(root, sOrder);
        getPreorder(subRoot, tOrder);
        return kmp();
    }
};