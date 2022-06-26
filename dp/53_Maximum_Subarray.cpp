// 2022.04.06
// greedy
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            res = count > res ? count : res;
            if(count <= 0){
                count = 0;
            }
        }
        return res;
    }
};

// 2022.04.13
// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 2022.06.26
// O(n) dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0;
        int n = nums.size();
        int res = -0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            dp = max(dp, 0) + nums[i];
            res = max(res, dp);
        }
        return res;
    }
};