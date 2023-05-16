// 2023.05.16

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= d; j++) {
                int cost = 0;
                for(int k = 1; k <= i; k++) {
                    cost = max(cost, jobDifficulty[i - k]);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }
        if(dp[n][d] == 0x3f3f3f3f) {
            return -1;
        }
        return dp[n][d];
    }
};