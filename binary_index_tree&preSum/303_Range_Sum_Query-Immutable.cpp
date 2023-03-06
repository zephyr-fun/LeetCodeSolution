// 2022.05.15
class NumArray {
public:
    NumArray(vector<int>& nums): prefix(nums.size(), 0) {
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2022.06.01
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums): prefix(nums.size(), 0) {
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int leftVal = left == 0 ? 0 : prefix[left - 1];
        int rightVal = prefix[right];
        return rightVal - leftVal;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2022.06.07
class NumArray {
public:
    NumArray(vector<int>& nums): sum_(nums.size() + 1, 0) { // n + 1 avoid overflow
        int n = nums.size();
        for(int i = 1; i <= n; i++) {
            sum_[i] = sum_[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum_[right + 1] - sum_[left];
    }
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2022.06.15
class NumArray {
public:
    NumArray(vector<int>& nums): sum_(nums.size() + 1, 0) {
        int n = nums.size();
        for(int i = 1; i <= n; i++) {
            sum_[i] = sum_[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum_[right + 1] - sum_[left];
    }
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2022.10.25
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2022.12.02
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// 2023.03.06
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
private:
    vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */