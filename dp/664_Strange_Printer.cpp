// 2022.11.16
// https://leetcode.cn/problems/strange-printer/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-xqeo9/
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp)); // dp[i][j] refers to the minimum print cnt of i->j
        for(int len = 1; len <= n; len++) {
            for(int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                dp[l][r] = dp[l + 1][r] + 1;
                for(int k = l + 1; k <= r; k++) {
                    if(s[l] == s[k]) {
                        dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};