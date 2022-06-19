// 2022.06.19
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> intrests(m + 1, vector<int>(n + 1, 0));
        for(auto& price : prices) {
            intrests[price[0]][price[1]] = price[2];
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = intrests[i][j];
                for(int k = 1; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                }
                for(int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};