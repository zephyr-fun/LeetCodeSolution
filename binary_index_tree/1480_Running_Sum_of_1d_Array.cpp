// 2022.05.14
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
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
    vector<int> runningSum(vector<int>& nums) {
        FenwickTree tree(nums.size());
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            tree.update(i + 1, nums[i]);
            res[i] = tree.query(i + 1);
        }
        return res;
    }
};