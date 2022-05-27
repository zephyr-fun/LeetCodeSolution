// 2022.05.26
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
        vector<int> res;
        SegmentTree* tree = new SegmentTree();
        int mx = 0;
        for (auto& p : positions)
        {
            int left = p[0], width = p[1], right = left + width - 1;
            int height = tree->query(left, right) + width;
            mx = max(mx, height);
            res.push_back(mx);
            tree->update(left, right, height);
        }
        return res;
    }
};