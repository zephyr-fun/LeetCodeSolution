// 2022.07.03
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dp;
    vector<vector<int>> grid;
    const int mod = 1e9 + 7;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dfs(int x, int y) {
        int& v = dp[x][y];
        if(v != -1) {
            return v;
        }
        v = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[x][y] < grid[nx][ny]) {
                v = (v + dfs(nx, ny)) % mod;
            }
        }
        return v;
    }
    int countPaths(vector<vector<int>>& grid_) {
        grid = grid_;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = (res + dfs(i, j)) % mod;
            }
        }
        return res;
    }
};