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


// 2022.04.29
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int max = INT_MIN;
        int index;
        for(int i = left; i <= right; i++) {
            if(nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = helper(nums, left, index - 1);
        root->right = helper(nums, index + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) {
            return nullptr;
        }
        TreeNode* res = helper(nums, 0, nums.size() - 1);
        return res;
    }
};

// 2022.08.20
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
    TreeNode* build(int left, int right, vector<int>& nums) {
        if(left > right) {
            return nullptr;
        }
        int maxVal = -0x3f3f3f3f;
        int maxIdx = -1;
        for(int i = left; i <= right; i++) {
            if(maxVal < nums[i]) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* cur = new TreeNode(maxVal);
        cur->left = build(left, maxIdx - 1, nums);
        cur->right = build(maxIdx + 1, right, nums);
        return cur;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return build(0, n - 1, nums);
    }
};

// 2022.08.20
// monotonic stack
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* st[1007];
        int head = 0;
        int tail = 0;
        for(auto num : nums) {
            TreeNode* cur = new TreeNode(num);
            while(head < tail && num > st[tail - 1]->val) {
                cur->left = st[tail - 1];
                tail--;
            }
            if(head < tail) {
                st[tail - 1]->right = cur;
            }
            st[tail] = cur;
            tail++;
        }
        return st[head];
    }
};

// 2022.09.26
class Solution {
public:
    vector<int> nums;
    TreeNode* traversal(int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int maxVal = nums[left];
        int idx = left;
        for(int i = left; i <= right; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                idx = i;
            }
        }
        TreeNode* cur = new TreeNode(maxVal);
        cur->left = traversal(left, idx - 1);
        cur->right = traversal(idx + 1, right);
        return cur;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums_) {
        nums = nums_;
        int n = nums.size();
        return traversal(0, n - 1);
    }
};

// 2023.03.19
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
    vector<int> nums;
    TreeNode* build(int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int maxIdx = left;
        int maxVal = nums[left];
        for(int i = left; i <= right; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* cur = new TreeNode(maxVal);
        cur->left = build(left, maxIdx - 1);
        cur->right = build(maxIdx + 1, right);
        return cur;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums_) {
        nums = nums_;
        int n = nums_.size();
        return build(0, n - 1);
    }
};

// with monotolic stack
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        stack<TreeNode*> st;
        for(int i = 0; i < n; i++) {
            TreeNode* cur = new TreeNode(nums[i]);
            while(!st.empty() && st.top()->val < nums[i]) { // cur->val
                cur->left = st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.top()->right = cur;
            }
            st.push(cur);
        }
        TreeNode* res = nullptr;
        while(!st.empty()) {
            res = st.top();
            st.pop();
        }
        return res;
    }
};

// 2023.03.24
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        stack<TreeNode*> st;
        for(int i = 0; i < n; i++) {
            TreeNode* cur = new TreeNode(nums[i]);
            while(!st.empty() && st.top()->val < nums[i]) {
                cur->left = st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.top()->right = cur;
            }
            st.push(cur);
        }
        TreeNode* res = nullptr;
        while(!st.empty()) {
            res = st.top();
            st.pop();
        }
        return res;
    }
};