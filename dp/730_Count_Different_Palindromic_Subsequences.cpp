// 2022.06.10
// general version
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int len = 1; len < n; len++) {
            for(int i = 0; i < n - len; i++) {
                const int j = i + len;
                if(s[i] == s[j]) {
                    dp[i][j] = 2 * dp[i + 1][j - 1];
                    int l = i + 1;
                    int r = j - 1;
                    while(l <= r && s[l] != s[i]) {
                        l++;
                    }
                    while(l <= r && s[r] != s[i]) {
                        r--;
                    }
                    if(l == r) {
                        dp[i][j] += 1;
                    }
                    else if(l > r) {
                        dp[i][j] += 2;
                    }
                    else {
                        dp[i][j] -= dp[l + 1][r - 1];
                    }
                }
                else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] > 0 ? dp[i][j] % mod : (dp[i][j] + mod) % mod;
            }
        }
        return dp[0][n - 1];
    }
};

// focus on {a, b, c, d} version
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int L[4];
        int R[4];
        memset(L, -1, sizeof(L));
        for(int i = n - 1; i >= 0; i--) {
            L[s[i] - 'a'] = i;
            memset(R, -1, sizeof(R));
            for(int j = i; j < n; j++) {
                R[s[j] - 'a'] = j;
                for(int k = 0; k < 4; k++) {
                    if(L[k] == -1 || R[k] == -1) {
                        continue;
                    }
                    int l = L[k];
                    int r = R[k];
                    if(l == r) {
                        dp[i][j] = (dp[i][j] + 1) % mod;
                    }
                    else if(l + 1 == r) {
                        dp[i][j] = (dp[i][j] + 2) % mod;
                    }
                    else {
                        dp[i][j] = (dp[i][j] + dp[l + 1][r - 1] + 2) % mod;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};