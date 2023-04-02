// 2023.04.02
// 区间DP
// https://www.bilibili.com/video/BV1Gs4y1E7EU/
// dfs version with cache
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(i + 1 == j) {
                return 0;
            }
            if(dp[i][j] >= 0) {
                return dp[i][j];
            }
            int res = 0x3f3f3f3f;
            for(int k = i + 1; k < j; k++) {
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            dp[i][j] = res;
            return res;
        };
        return dfs(0, n - 1);
    }
};

// dp
// dp[i][j] = max_{from k = i + 1 to j - 1}(dp[i][k] + dp[k][j] + v[i] * v[j] * v[k])
// i < k && k < j
// i from n - 1 to 0, j from i + 1 to n - 1
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 3; i >= 0; i--) {
            for(int j = i + 2; j < n; j++) {
                dp[i][j] = 0x3f3f3f3f;
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};