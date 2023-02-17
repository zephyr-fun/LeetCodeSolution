// 2023.02.17
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rs(n, vector<int>(m + 1, 0));
        vector<vector<int>> cs(m, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rs[i][j + 1] = rs[i][j] + grid[i][j];
                cs[j][i + 1] = cs[j][i] + grid[i][j];
            }
        }
        for(int d = min(n, m); d > 0; d--) {
            for(int i = 0; i <= n - d; i++) {
                for(int j = 0; j <= m - d; j++) {
                    if(rs[i][j + d] - rs[i][j] == d && // up
                       cs[j][i + d] - cs[j][i] == d && // left
                       rs[i + d - 1][j + d] - rs[i + d - 1][j] == d && // down
                       cs[j + d - 1][i + d] - cs[j + d - 1][i] == d // right
                       ) {
                           return d * d;
                       }
                }
            }
        }
        return 0;
    }
};