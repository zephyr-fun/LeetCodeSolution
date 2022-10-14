// 2022.06.06
// O(n), with two prefix multiply
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ms1(n + 7, 0);
        vector<int> ms2(n + 7, 0);
        ms1[0] = 1;
        ms2[n + 1] = 1;
        for(int i = 1; i <= n; i++) {
            ms1[i] = ms1[i - 1] * nums[i - 1];
        }
        for(int i = n; i >= 1; i--) {
            ms2[i] = ms2[i + 1] * nums[i - 1];
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = ms1[i] * ms2[i + 2];
        }
        return res;
    }
};

// 2022.06.24
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> surfix(n + 1, 0);
        prefix[0] = 1;
        surfix[n] = 1;
        for(int i = 1, j = n - 1; i <= n; i++, j--) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            surfix[j] = surfix[j + 1] * nums[j];
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = prefix[i] * surfix[i + 1];
        }
        return res;
    }
};

// 2022.10.09
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            left[i] = nums[i - 1] * left[i - 1];
            right[n - 1 - i] = nums[n - i] * right[n - i];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};

// 2022.10.14
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
            right[n - i - 1] = right[n - i] * nums[n - i];
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};