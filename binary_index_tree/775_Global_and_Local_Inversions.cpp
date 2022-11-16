// 2022.11.16
class FenwickTree {
public:
    FenwickTree(int n) : sums_(n + 1) {}

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
    static inline int lowbit(int x) {
        return x & -x;
    }
    vector<int> sums_;
};
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long long cnt1 = 0;
        long long cnt2 = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                cnt1++;
            }
        }
        vector<int> temp;
        for(auto num : nums) {
            temp.emplace_back(num);
        }
        unordered_map<int, int> map;
        int idx = 0;
        sort(temp.begin(), temp.end());
        for(auto num : temp) {
            map[num] = idx;
            idx++;
        }
        FenwickTree tree(n);
        for(int i = n - 1; i >= 0; i--) {
            cnt2 += tree.query(map[nums[i]]);
            tree.update(map[nums[i]] + 1, 1);
        }
        return cnt1 == cnt2;
    }
};