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