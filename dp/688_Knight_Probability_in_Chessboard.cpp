// 2022.12.14
// dp[r][c][step]
// left step or remain step
// https://leetcode.cn/problems/knight-probability-in-chessboard/solution/gong-shui-san-xie-jian-dan-qu-jian-dp-yu-st8l/
// https://www.acwing.com/video/2496/
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double dp[25][25][101];
        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j][k] = 1;
            }
        }
        for(int step = k - 1; step >= 0; step--) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int u = 0; u < 8; u++) {
                        int x = i + dx[u];
                        int y = j + dy[u];
                        if(x >= 0 && x < n && y >= 0 && y < n) {
                            dp[i][j][step] += dp[x][y][step + 1] / 8;
                        }
                    }
                }
            }
        }
        return dp[row][column][0];
    }
};