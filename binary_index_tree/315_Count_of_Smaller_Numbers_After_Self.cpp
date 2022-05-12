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