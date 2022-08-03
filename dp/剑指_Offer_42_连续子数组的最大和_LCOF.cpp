// 2022.06.26
// Forgetting this solution is very unwarranted
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = 0;
        int res = -0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            dp = max(dp, 0) + nums[i];
            res = max(res, dp);
        }
        return res;
    }
};

// 2022.08.03
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // dp[i] means the max value we can get end with nums[i]
        int dp = 0;
        int res = -0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            dp = max(0, dp) + nums[i];
            res = max(res, dp);
        }
        return res;
    }
};