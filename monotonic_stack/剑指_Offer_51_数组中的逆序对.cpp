// 2022.07.01
// fenwick tree + discretization
class FenwickTree {
public:
    FenwickTree(int n): sum_(n + 1, 0) {}

    void update(int idx, int delta) {
        while(idx < sum_.size()) {
            sum_[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += sum_[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
private:
    vector<int> sum_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int idx = 1;
        unordered_map<int, int> map;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(auto num : sorted) {
            map[num] = idx;
            idx++;
        }
        FenwickTree tree(n);
        int res = 0;
        for(int i = n - 1; i >= 0; i--) {
            res += tree.query(map[nums[i]] - 1);
            tree.update(map[nums[i]], 1);
        }
        return res;
    }
};