// 2022.10.14
// dp[i][j] refers to the number of first i chars, ends with 'a' + j
class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dp[0][s[0] - 'a'] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for(int j = 0; j < 26; j++) {
                if(s[i] - 'a' == j) {
                    dp[i][s[i] - 'a'] = (dp[i][s[i] - 'a'] + 1) % mod;
                    continue;
                }
                dp[i][s[i] - 'a'] = (dp[i][s[i] - 'a'] + dp[i - 1][j]) % mod;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            res = (res + dp[n - 1][i]) % mod;
        }
        return res;
    }
};

// remove i dim
class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dp(26, 0);
        dp[s[0] - 'a'] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                if(s[i] - 'a' == j) {
                    dp[s[i] - 'a'] = (dp[s[i] - 'a'] + 1) % mod;
                    continue;
                }
                dp[s[i] - 'a'] = (dp[s[i] - 'a'] + dp[j]) % mod;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};

// tea version
class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dp(26, 0);
        int tot = 0;
        for(auto c : s) {
            c -= 'a';
            int others = tot - dp[c];
            dp[c] = tot + 1;
            tot = ((dp[c] + others) % mod + mod) % mod;
        }
        
        return tot;
    }
};