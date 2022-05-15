// 2022.05.15
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    long long query(int i) {
        long long sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    vector<long long> sums_;
    static inline int lowbit(int i) {
        return i & (-i);
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        FenwickTree tree(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            tree.update(i + 1, nums[i]);
        }
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(tree.query(i + 1) >= (tree.query(nums.size()) - tree.query(i + 1))) {
                res++;
            }
        }
        return res;
    }
};