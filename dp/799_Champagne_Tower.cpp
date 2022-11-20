// 2022.11.20
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0));
        dp[0][0] = poured;
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] > 1) {
                    double x = (dp[i][j] - 1) / 2;
                    dp[i + 1][j] += x;
                    dp[i + 1][j + 1] += x;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};