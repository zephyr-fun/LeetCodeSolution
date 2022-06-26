// 2022.06.26
// single dp, then multiply
class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = dp[i - 1][0];
        }
        long long sum = (long long)(dp[n - 1][0] + dp[n - 1][1]);
        int res = sum * sum % mod;
        return res;
    }
};