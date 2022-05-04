// 2022.05.04
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // dp[i][j] refers to the minimum cost of getting pos(i, j)
        vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));
        int res = 0x3f3f3f3f;
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                }
                else if(j == n - 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];
                }
            }
        }
        for(int j = 0; j < n; j++) {
            res = min(res, dp[n - 1][j]);
        }
        return res;
    }
};

// optim space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // dp[i & 1][j] refers to the minimum cost of getting pos(i, j)
        vector<vector<int>> dp(2, vector<int>(n, 0x3f3f3f3f));
        int res = 0x3f3f3f3f;
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    dp[i & 1][j] = min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j + 1]) + matrix[i][j];
                }
                else if(j == n - 1) {
                    dp[i & 1][j] = min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1]) + matrix[i][j];
                }
                else {
                    dp[i & 1][j] = min(dp[(i - 1) & 1][j - 1], min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j + 1])) + matrix[i][j];
                }
            }
        }
        for(int j = 0; j < n; j++) {
            res = min(res, dp[(n - 1) & 1][j]);
        }
        return res;
    }
};