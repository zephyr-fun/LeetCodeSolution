// 2022.07.09
// fenwick tree with discretization
class FenwickTree {
public:
    FenwickTree(int n) : sums_(n + 1, 0) {}

    void update(int idx, int delta) {
        while(idx < sums_.size()) {
            sums_[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += sums_[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
private:
    vector<int> sums_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        FenwickTree tree(n);
        int res = 0;
        unordered_map<int, int> map;
        vector<int> sorted(n, 0);
        for(int i = 0; i < n; i++) {
            sorted[i] = nums[i];
        }
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; i++) {
            map[sorted[i]] = i + 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            res += tree.query(map[nums[i]] - 1);
            tree.update(map[nums[i]], 1);
        }
        return res;
    }
};