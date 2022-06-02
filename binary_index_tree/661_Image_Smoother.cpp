// 2022.06.02
class Solution {
public:
    vector<vector<int>> sum;
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        sum.resize(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int row1 = max(0, i - 1);
                int col1 = max(0, j - 1);
                int row2 = min(m - 1, i + 1);
                int col2 = min(n - 1, j + 1);
                int cnt = (row2 - row1 + 1) * (col2 - col1 + 1);
                int total = sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
                res[i][j] = total / cnt;
            }
        }
        return res;
    }
};