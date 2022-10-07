// 2022.10.07
// sliding window
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int right = 0;
        int n = nums.size();
        int cur = 0;
        int res = 0;
        while(right < n) {
            cur += nums[right];
            while(right < n - 1 && nums[right] < nums[right + 1]) {
                right++;
                cur += nums[right];
            }
            res = max(res, cur);
            cur = 0;
            right++;
        }
        return res;
    }
};

// dp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};