// 2022.06.22
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        set<long long> allNum; // set has order ! that's why we can use Principle of capacitive repulsion through BIT and map
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            preSum.emplace_back(sum);
        }
        for(auto x : preSum) {
            allNum.insert(x);
            allNum.insert(x - lower);
            allNum.insert(x - upper);
        }
        int idx = 0;
        unordered_map<long long, int> map;
        for(auto num : allNum) {
            map[num] = idx;
            idx++;
        }
        int res = 0;
        FenwickTree tree(allNum.size());
        for(int i = 0; i <= n; i++) { // i starts from 0, so that we can have a safe left bound
            int left = map[preSum[i] - upper];
            int right = map[preSum[i] - lower];
            res += tree.query(right + 1) - tree.query(left);
            // cout << "i:" << i << "presum:" << preSum[i] << "left:" << left << "right:" << right << "Qr:" << tree.query(right + 1) << "Ql:" << tree.query(left) << endl;
            tree.update(map[preSum[i]] + 1, 1);
        }
        return res;
    }
};