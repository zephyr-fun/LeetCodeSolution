// 2022.06.02
// \textit{dp}[0][0] = \text{True}dp[0][0]=True，即当字符串 ss 和模式 pp 均为空时，匹配成功；

// \textit{dp}[i][0] = \text{False}dp[i][0]=False，即空模式无法匹配非空字符串；

// \textit{dp}[0][j]dp[0][j] 需要分情况讨论：因为星号才能匹配空字符串，所以只有当模式 pp 的前 jj 个字符均为星号时，\textit{dp}[0][j]dp[0][j] 才为真。

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

// 2022.06.16
// The above version writes the boundary processing into the main loop, 
// which is a bit difficult to understand, 
// and the following version is the code to break out the processing
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        s = " " + s;
        p = " " + p;
        // init
        for(int j = 1; j <= m; j++) {
            if(p[j] == '*') {
                dp[0][j] = true;
            }
            else {
                break;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                }
            }
        }
        return dp[n][m];
    }
};

// 2022.09.22
// p[j] == '*'
// f[i][j] = f[i][j - 1] || f[i - 1][j - 1] || ... || f[0][j - 1]
// f[i - 1][j] = f[i - 1][j - 1] || f[i - 2][j - 1] || ... || f[0][j - 1]
// f[i][j] = f[i][j - 1] || f[i - 1][j]
// p[j] != '*'
// f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] = '?')
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        s = " " + s;
        p = " " + p;
        for(int i = 1; i <= m; i++) {
            if(p[i] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                }
            }
        }
        return dp[n][m];
    }
};