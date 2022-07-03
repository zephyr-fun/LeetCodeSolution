// 2022.07.03
// dp 
// https://www.bilibili.com/video/BV1Fa411p7rY?spm_id_from=333.337.search-card.all.click&vd_source=1e5e0fe23d3d704a3f15a4928671d9ac
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(forget + 1, 0));
        // dp[i][j] refers to total sum num of keep the secret for 1-j days on ith day, reduce O(n) by prefix
        for(int i = 1; i <= forget; i++) {
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= forget; j++) {
                if(j == 1) {
                    dp[i][j] = dp[i - 1][forget - 1] - dp[i - 1][delay - 1] % mod;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] - dp[i - 1][j - 2] % mod;
                }
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
        return (dp[n][forget] + mod) % mod;
    }
};