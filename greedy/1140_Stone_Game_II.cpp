// 2023.02.22
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1));
        vector<int> preSum(n + 1);
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + piles[i - 1];
        }
        for(int i = n; i > 0; i--) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; i + k - 1 <= n && k <= j * 2; k++) {
                    dp[i][j] = max(dp[i][j], preSum[n] - preSum[i - 1] - dp[i + k][max(k, j)]);
                }
            }
        }
        return dp[1][1];
    }
};