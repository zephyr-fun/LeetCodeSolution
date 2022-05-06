// 2022.05.06
class Solution {
public:
    int mod = 1000000007;
    int _m, _n, _maxMove;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        _m = m;
        _n = n;
        _maxMove = maxMove;
        vector<vector<int>> dp(m * n, vector<int>(maxMove + 1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    add(i, j, dp);
                }
                if(i == m - 1) {
                    add(i, j, dp);
                }
                if(j == 0) {
                    add(i, j, dp);
                }
                if(j == n - 1) {
                    add(i, j, dp);
                }
            }
        }
        int dirs[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int step = 1; step <= maxMove; step++) {
            for(int k = 0; k < m * n; k++) {
                int x = parse(k)[0];
                int y = parse(k)[1];
                for(auto dir : dirs) {
                    int nextX = x + dir[0];
                    int nextY = y + dir[1];
                    if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                        dp[k][step] += dp[getIndex(nextX, nextY)][step - 1];
                        dp[k][step] %= mod;
                    }
                }
            }
        }
        return dp[getIndex(startRow, startColumn)][maxMove];
    }
    void add(int x, int y, vector<vector<int>>& dp) {
        int idx = getIndex(x, y);
        for(int j = 1; j <= _maxMove; j++) {
            dp[idx][j]++;
        }
    }
    int getIndex(int x, int y) {
        return x * _n + y;
    }
    vector<int> parse(int idx) {
        vector<int> res(2, 0);
        res[0] = idx / _n;
        res[1] = idx % _n;
        return res;
    }
};