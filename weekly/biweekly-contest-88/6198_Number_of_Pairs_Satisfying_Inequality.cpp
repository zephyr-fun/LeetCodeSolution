// 2022.10.01
// FenwickTree + nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long res = 0;
        int n = nums1.size();
        vector<int> temp(n);
        unordered_set<int> set;
        for(int i = 0; i < n; i++) {
            temp[i] = nums1[i] - nums2[i];
            set.insert(temp[i]);
            set.insert(temp[i] + diff);
        }
        vector<int> setq(set.begin(), set.end());
        int m = setq.size();
        sort(setq.begin(), setq.end());
        unordered_map<int, int> map;
        for(int i = 0; i < m; i++) {
            map[setq[i]] = i;
        }
        FenwickTree tree(m);
        for(int i = 0; i < n; i++) {
            res += tree.query(map[temp[i] + diff] + 1);
            tree.update(map[temp[i]] + 1, 1);
        }
        return res;
    }
};