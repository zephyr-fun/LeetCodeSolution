// 2022.05.05
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minLine = 0x3f3f3f3f;
        int minLineIndex;
        int subMinLine = 0x3f3f3f3f;
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));
        for(int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
            if(dp[0][j] < minLine) {
                subMinLine = minLine;
                minLine = dp[0][j];
                minLineIndex = j;
            }
            else if(dp[0][j] < subMinLine) { // record sub minimum value
                subMinLine = dp[0][j];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j != minLineIndex) {
                    dp[i][j] = minLine + grid[i][j];
                }
                else {
                    dp[i][j] = subMinLine + grid[i][j];
                }
            }
            minLine = 0x3f3f3f3f;
            for(int j = 0; j < n; j++) {
                if(dp[i][j] < minLine) {
                    subMinLine = minLine;
                    minLine = dp[i][j];
                    minLineIndex = j;
                }
                else if(dp[i][j] < subMinLine) {
                    subMinLine = dp[i][j];
                }
            }
        }
        return minLine;
    }
};

// optim space from n to 2