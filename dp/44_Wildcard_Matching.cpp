// 2022.06.02
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        s = " " + s;
        p = " " + p;
        dp[0][0] = true;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || (i - 1 >= 0 && dp[i - 1][j]);
                }
                else {
                    dp[i][j] = (i - 1 >= 0) && dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                }
            }
        }
        return dp[n][m];
    }
};