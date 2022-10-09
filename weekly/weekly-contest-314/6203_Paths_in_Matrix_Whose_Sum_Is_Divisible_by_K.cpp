// 2022.10.09
// do not use unordered_map -> TLE warning
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int tar) {
        int mod = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(tar, 0)));
        dp[0][0][grid[0][0] % tar]++;
        for(int i = 1; i < n; i++) {
            for(int k = 0; k < tar; k++) {
                dp[i][0][(grid[i][0] + k) % tar] = (dp[i][0][(grid[i][0] + k) % tar] + dp[i - 1][0][k]) % mod;
            }
        }
        for(int j = 1; j < m; j++) {
            for(int k = 0; k < tar; k++) {
                dp[0][j][(grid[0][j] + k) % tar] = (dp[0][j][(grid[0][j] + k) % tar] + dp[0][j - 1][k]) % mod;
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                for(int k = 0; k < tar; k++) {
                    dp[i][j][(grid[i][j] + k) % tar] = (dp[i][j][(grid[i][j] + k) % tar] + dp[i - 1][j][k]) % mod;
                }
                for(int k = 0; k < tar; k++) {
                    dp[i][j][(grid[i][j] + k) % tar] = (dp[i][j][(grid[i][j] + k) % tar] + dp[i][j - 1][k]) % mod;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};