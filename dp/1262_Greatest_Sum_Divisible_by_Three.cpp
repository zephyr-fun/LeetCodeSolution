// 2022.08.15
// plain dp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -0x3f3f3f3f;
        dp[0][2] = -0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            if(nums[i - 1] % 3 == 0) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + nums[i - 1]);
            }
            else if(nums[i - 1] % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]);
            }
            else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
            }
        }
        return dp[n][0];
    }
};

// optim dp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int dp[3] = {0};
        for(int i = 0; i < n; i++) {
            int a = dp[0] + nums[i];
            int b = dp[1] + nums[i];
            int c = dp[2] + nums[i];
            dp[a % 3] = max(dp[a % 3], a);
            dp[b % 3] = max(dp[b % 3], b);
            dp[c % 3] = max(dp[c % 3], c);
        }
        return dp[0];
    }
};