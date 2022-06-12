// 2022.06.12
// pity
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0x3f3f3f3f));
        for(int j = 0; j < m; j++) {
            dp[0][j] = grid[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
        }
        int res = 0x3f3f3f3f;
        for(int j = 0; j < m; j++) {
            res = min(res, dp[n - 1][j]);
        }
        return res;
    }
};