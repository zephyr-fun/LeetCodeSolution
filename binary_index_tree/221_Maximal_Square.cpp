// 2022.12.07
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int>> preSum(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + matrix[i - 1][j - 1] - '0' - preSum[i - 1][j - 1];
            }
        }
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                for(int j = 0; j <= m - len; j++) {
                    int a = i + len - 1;
                    int b = j + len - 1;
                    int temp = preSum[a + 1][b + 1] - preSum[a + 1][j] - preSum[i][b + 1] + preSum[i][j];
                    if(temp == len * len) {
                        res = max(res, temp);
                    }
                }
            }
        }
        return res;
    }
};

// dp
// https://leetcode.cn/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0 || m == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; // draw a figure
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};