// 2022.05.11
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta) { // update delta
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

class NumArray {
public:
    NumArray(vector<int>& nums): nums_(std::move(nums)), tree_(nums_.size()) {
        for(int i = 0; i < nums_.size(); i++) {
            tree_.update(i + 1, nums_[i]); // delta
        } // nlogn
    }
    
    void update(int index, int val) {
        tree_.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree_.query(right + 1) - tree_.query(left);
    }
private:
    vector<int> nums_;
    FenwickTree tree_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


// 2022.05.15
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta) { // update delta
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

class NumArray {
public:
    NumArray(vector<int>& nums): nums_(std::move(nums)), tree_(nums_.size()) {
        for(int i = 0; i < nums_.size(); i++) {
            tree_.update(i + 1, nums_[i]);
        } // nlogn
    }
    
    void update(int index, int val) {
        tree_.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree_.query(right + 1) - tree_.query(left);
    }
private:
    vector<int> nums_;
    FenwickTree tree_;
};

// 2022.06.07
class FenWickTree {
public:
    FenWickTree(int n): sums_(n + 1, 0) {}

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
    int lowbit(int x) {
        return x & (-x);
    }
};
class NumArray {
public:
    NumArray(vector<int>& nums): tree(nums.size()) {
        int n = nums.size();
        nums_ = nums;
        for(int i = 0; i < n; i++) {
            tree.update(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        tree.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree.query(right + 1) - tree.query(left);
    }
private:
    FenWickTree tree;
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */