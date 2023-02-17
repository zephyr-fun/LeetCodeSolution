// sliding window
// 2022.05.26
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int cur = 0;
        vector<int> rotateNums(2 * n, 0);
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            cur += nums[i] * i;
            rotateNums[i] = nums[i];
            rotateNums[i + n] = nums[i];
        }
        int maxNow = cur;
        for(int i = 1; i < n; i++) {
            cur -= (sum - nums[i - 1]);
            cur += nums[i - 1] * (n - 1);
            maxNow = max(cur, maxNow);
        }
        return maxNow;
    }
};

// 2022.06.05
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int cur = 0;
        int res = 0;
        vector<int> rotateNums(2 * n, 0);
        for(int i = 0; i < n; i++) {
            cur += i * nums[i];
            sum += nums[i];
            rotateNums[i] = nums[i];
            rotateNums[i + n] = nums[i];
        }
        res = cur;
        for(int i = 1; i < n; i++) {
            cur -= (sum - nums[i - 1]);
            cur += (n - 1) * nums[i - 1];
            res = max(res, cur);
        }
        return res;
    }
};

// 2022.12.02
// 核心思路是，比较两个相邻的要计算的值，看这两个值的差 F(i)-F(i-1)，总结成一个公式，这样就能从 F(0) 出发，O(1) 地计算出下一个 F 值。
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum[2 * n + 10];
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= 2 * n; i++) {
            sum[i] = sum[i - 1] + nums[(i - 1) % n];
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res += nums[i - 1] * (i - 1);
        }
        for(int i = n + 1, cur = res; i < 2 * n; i++) {
            cur += nums[(i - 1) % n] * (n - 1);
            cur -= sum[i - 1] - sum[i - n];
            res = max(res, cur);
        }
        return res;
    }
};