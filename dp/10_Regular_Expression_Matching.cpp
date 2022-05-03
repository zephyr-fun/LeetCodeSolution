// 2022.05.03
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        s = " " + s;
        p = " " + p;
        // dp[i][j] refers to front ith chars in s whether match front jth chars in p
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= n; i++) { // i starts from 0
            for(int j = 1; j <= m; j++) {
                if(j + 1 <= m && p[j + 1] == '*') {
                    continue;
                }
                else if(i - 1 >= 0 && p[j] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if(p[j] == '*') {
                    dp[i][j] = (j - 2 >= 0 && dp[i][j - 2]) || (i - 1 >= 0 && dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return dp[n][m];
    }
};