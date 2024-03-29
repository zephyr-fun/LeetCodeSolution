class NumArray {
    /* 两类操作
    1. 更新数组下标对应的值
    2. 返回某个范围内的元素总和
    // 但节点修改的线段树，不需要设置懒标记
    */
  private:
    void build_tree(vector<int> &nums, int tr[], int node, int start, int end) {
        /*
        建立线段树
        node是要建立的当前节点，start和end是节点的范围,两端包含
        注意：下标从0开始
        */
        if (start == end) { // 建立当前节点
            tr[node] = nums[start];
        } else {
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int mid = (start + end) / 2;
            build_tree(nums, tr, left_node, start, mid);
            build_tree(nums, tr, right_node, mid + 1, end);
            tr[node] = tr[left_node] + tr[right_node];
        }
    }
    void update_tree(int tr[], int node, int start, int end, int idx, int val) {
        /*
        修改线段树
        将下标idx改为val,node是线段树节点序号，start和end是线段树节点在原数组的范围
         */
        if (start == end) {
            tr[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx < start || idx > end) return;
        if (start <= idx && idx <= mid) { // 修改左分支
            update_tree(tr, left_node, start, mid, idx, val);
        } else { // 修改右分支
            update_tree(tr, right_node, mid + 1, end, idx, val);
        }
        tr[node] = tr[left_node] + tr[right_node];
    }
    int query_tree(int tr[], int node, int start, int end, int L, int R) {
        /*
        线段树查询，
        查询区间L,R的和，两端包含
         */
        if (R < start || L > end)
            return 0;
        else if (start == end)
            return tr[node];
        else if (start >= L && end <= R)
            return tr[node];
        else {
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int sum_left = query_tree(tr, left_node, start, mid, L, R);
            int sum_right = query_tree(tr, right_node, mid + 1, end, L, R);
            return sum_left + sum_right;
        }
    }
    // int tr[120000];
    int *tr;
    int n;

  public:
    NumArray(vector<int> &nums) {
        /* 使用nums初始化线段树，下标从0开始 */
        n = nums.size();
        tr = new int[n * 4];
        memset(tr, 0, sizeof(tr));
        build_tree(nums, tr, 0, 0, n - 1);
    }
    ~NumArray() { delete[] tr; }

    void update(int index, int val) {
        /* 更新对象中的值 */
        update_tree(tr, 0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        /* 区域求和 */
        int res = query_tree(tr, 0, 0, n - 1, left, right);
        return res;
    }
};

// template
class Node {
public:
    Node* leftNode;
    Node* rightNode;
    int left;
    int right;
    int mid;
    int val;
    int add;

    Node(int left, int right) {
        this->left = left;
        this->right = right;
        this->mid = left + (right - left) / 2;
        this->leftNode = this->rightNode = nullptr;
        val = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }

    void update(int left, int right, int val) {
        update(left, right, val, root);
    }

    void update(int left, int right,int val, Node* node) {
        if (left > right) return;
        if (node->left >= left && node->right <= right)
        {
            node->val = val;
            node->add = val;
            return;
        }
        pushdown(node);
        if (left <= node->mid) update(left, right, val, node->leftNode);
        if (right > node->mid) update(left, right, val, node->rightNode);
        pushup(node);
    }

    int query(int left, int right) {
        return query(left, right, root);
    }

    int query(int left, int right, Node* node) {
        if (left > right) return 0;
        if (node->left >= left && node->right <= right) return node->val;
        pushdown(node);
        int val = 0;
        if (left <= node->mid) val = max(val, query(left, right, node->leftNode));
        if (right > node->mid) val = max(val, query(left, right, node->rightNode));
        return val;
    }

    void pushup(Node* node) {
        node->val = max(node->leftNode->val, node->rightNode->val);
    }

    void pushdown(Node* node) {
        if (!node->leftNode) node->leftNode = new Node(node->left, node->mid);
        if (!node->rightNode) node->rightNode = new Node(node->mid + 1, node->right);
        if (node->add)
        {
            Node* left = node->leftNode;
            Node* right = node->rightNode;
            left->val = node->add;
            right->val = node->add;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        SegmentTree* tree = new SegmentTree();
        int mx = 0;
        for (auto& p : positions)
        {
            int l = p[0], w = p[1], r = l + w - 1;
            int h = tree->query(l, r) + w;
            mx = max(mx, h);
            ans.push_back(mx);
            tree->modify(l, r, h);
        }
        return ans;
    }
};

// template
class SegmentTree {
public:
    SegmentTree(vector<int>& arr, int start, int end, int node_idx): tree(2 * arr.size(), 0) {
        build_tree(arr, start, end, node_idx); // node_idx = 1
    }

    void build_tree(vector<int>& arr, int start, int end, int node_idx) {
        if(start == end) {
            tree[node_idx] = arr[start];
        }
        else {
            int left_node = 2 * node_idx;
            int right_node = 2 * node_idx + 1;
            int mid = start + (end - start) / 2;
            build_tree(arr, start, mid, left_node);
            build_tree(arr, mid + 1, end, right_node);
            tree[node_idx] = tree[left_node] + tree[right_node];
        }
    }

    int query(int start, int end, int left, int right, int node_idx) {
        if(left > end || right < start) {
            return 0;
        }
        else if(left <= start && right >= end) {
            return tree[node_idx];
        }
        else {
            int left_node = 2 * node_idx;
            int right_node = 2 * node_idx + 1;
            int mid = start + (end - start) / 2;
            int left_sum = query(start, mid, left, right);
            int right_sum = query(mid + 1, end, left, right);
            return left_sum + right_sum;
        }
    }

    void update(int start, int end, int node_idx, int update_idx, int val) {
        if(start == end) {
            tree[node_idx] = val;
        }
        else {
            int left_node = 2 * node_idx;
            int right_node = 2 * node_idx + 1;
            int mid = start + (end - start) / 2;
            if(update_idx > mid) {
                update(mid + 1, end, right_node, update_idx, val);
            }
            else {
                update(start, mid, node_idx, update_idx, val);
            }
            tree[node_idx] = tree[left_node] + tree[right_node];
        }
    }
private:
    vector<int> tree;
};

// 2022.06.30
// zcy version