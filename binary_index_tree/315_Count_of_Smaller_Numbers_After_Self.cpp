// 2022.05.12
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
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> sums_;
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // sort the unique numbers
        set<int> sorted(nums.begin(), nums.end());
        // map the number to its rank
        unordered_map<int, int> ranks;
        int rank = 0;
        for(const auto num : sorted) {
            rank++;
            ranks[num] = rank;
        }
        vector<int> res;
        FenwickTree tree(ranks.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

// 2022.06.27
// FenwickTree + Discretization
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
    vector<int> countSmaller(vector<int>& nums) {
        int mod = 1e4 + 7;
        int n = nums.size();
        FenwickTree tree(1e5);
        vector<int> res(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            res[i] = tree.query(nums[i] + mod);
            tree.update(nums[i] + mod + 1, 1);
        }
        return res;
    }
};

// 2022.07.09
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
    vector<int> sums_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> sorted;
        for(auto num : nums) {
            sorted.emplace_back(num);
        }
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[sorted[i]] = i + 1;
        }
        FenwickTree tree(n);
        for(int i = n - 1; i >= 0; i--) {
            res[i] = tree.query(map[nums[i]] - 1);
            tree.update(map[nums[i]], 1);
        }
        return res;
    }
};