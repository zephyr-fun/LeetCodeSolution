// 2022.10.13
class FenwickTree {
public:
    FenwickTree(int n) : sums(n + 1) {}

    void update(int idx, int delta) {
        while(idx < sums.size()) {
            sums[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += sums[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
private:
    vector<int> sums;
    static inline int lowbit(int x) {
        return x & -x;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        FenwickTree tree(n);
        int res = 0;
        int last = 0;
        for(int i = 0; i < n; i++) {
            tree.update(arr[i] + 1, 1);
            if(tree.query(i + 1) - tree.query(last) == i - last + 1) {
                res++;
                last = i;
            }
        }
        return res;
    }
};