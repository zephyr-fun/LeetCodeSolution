// 2022.11.28
// 
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int m) {
        int n = nums.size();
        vector<double> sum(n + 10, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        vector<vector<double>> dp(n + 10, vector<double>(m + 10, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= min(i, m); j++) {
                if(j == 1) {
                    dp[i][1] = sum[i] / i;
                }
                else {
                    for(int k = 2; k <= i; k++) { // enumerate k cause near
                        dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + ((sum[i] - sum[k - 1]) / (i - k + 1)));
                    }
                }
            }
        }
        return dp[n][m];
    }
};