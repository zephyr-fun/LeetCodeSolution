// 2022.10.04
// recursion
class Solution {
public:
    vector<int> tree;
    bool traversal(int l, int r) {
        if(l >= r) {
            return true;
        }
        int p = l;
        while(tree[p] < tree[r]) {
            p++;
        }
        int m = p;
        while(tree[p] > tree[r]) {
            p++;
        }
        return p == r && traversal(l, m - 1) && traversal(m, r - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        tree = postorder;
        return traversal(0, tree.size() - 1);
    }
};

// monotonic stack
