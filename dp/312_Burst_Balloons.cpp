// 2022.10.28
// https://leetcode.cn/problems/burst-balloons/solutions/1930450/by-ac_oier-9r9c/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int len = 3; len <= n + 2; len++) {
            for(int l = 0; l + len - 1 <= n + 1; l++) {
                int r = l + len - 1;
                for(int k = l + 1; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + nums[l] * nums[k] * nums[r]);
                }
            }
        }
        return dp[0][n + 1];
    }
};