// 2022.05.04
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp[i][j] refers to the minimum cost of arriving ith floar jth pos
        int res = 0x3f3f3f3f;
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < m; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if(j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        for(int j = 0; j < n; j++) {
            res = min(res, dp[m - 1][j]);
        }
        return res;
    }
};

// optim space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp[i][j % 2] refers to the minimum cost of arriving ith floar jth pos
        int res = 0x3f3f3f3f;
        int m = triangle.size();
        vector<vector<int>> dp(2, vector<int>(m, 0x3f3f3f3f));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < m; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    dp[i & 1][j] = dp[(i - 1) & 1][j] + triangle[i][j];
                }
                else if(j == i) {
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i & 1][j] = min(dp[(i - 1) & 1][j - 1], dp[(i - 1) & 1][j]) + triangle[i][j];
                }
            }
        }
        for(int j = 0; j < m; j++) {
            res = min(res, dp[(m - 1) & 1][j]);
        }
        return res;
    }
};
