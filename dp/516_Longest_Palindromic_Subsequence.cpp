// 2022.04.14
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};

// 2022.11.15
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

// 2023.04.02
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n]; // 记忆化一下，否则会TLE
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(dp[i][j] >= 0) {
                return dp[i][j];
            }
            if(i > j) {
                return 0;
            }
            if(i == j) {
                return 1;
            }
            if(s[i] == s[j]) {
                dp[i][j] = dfs(i + 1, j - 1) + 2;
                return dp[i][j];
            }
            dp[i][j] = max(dfs(i + 1, j), dfs(i, j - 1));
            return dp[i][j];
        };
        return dfs(0, n - 1);
    }
};