// 2022.05.10
constexpr static int S = 8 * 8 * 8 * 8, K = 128;
constexpr static int dirs[]{-1, 0, 1, 0, -1};
static int f[S][K];
class Solution {
    vector<string> grid;
    int a, b, tx, ty, m, n;
    int dfs(int x, int y, int p, int q, int k) {
        int state = (x << 9) | (y << 6) | (p << 3) | q;
        if (k == K - 1) return f[state][k] = 1;
        if (x == p && y == q) return f[state][k] = 1;
        if (x == tx && y == ty) return f[state][k] = 0;
        if (p == tx && q == ty) return f[state][k] = 1;
        if (f[state][k] != -1) return f[state][k];
        if (k & 1) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= b; ++j) {
                    int np = p + dirs[i] * j, nq = q + dirs[i + 1] * j;
                    if (np < 0 || np >= n || nq < 0 || nq >= m) break;
                    if (grid[np][nq] == '#') break;
                    if (dfs(x, y, np, nq, k + 1) == 1) return f[state][k] = 1;
                }
            }
            return f[state][k] = 0;
        } else {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= a; ++j) {
                    int nx = x + dirs[i] * j, ny = y + dirs[i + 1] * j;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                    if (grid[nx][ny] == '#') break;
                    if (dfs(nx, ny, p, q, k + 1) == 0) return f[state][k] = 0;
                }
            }
            return f[state][k] = 1;
        }
    }
public:
    bool canMouseWin(vector<string>& _grid, int catJump, int mouseJump) {
        grid = move(_grid);
        n = grid.size(), m = grid[0].size(), a = mouseJump, b = catJump;
        for (int i = 0; i < S; ++i) fill_n(f[i], K, -1);
        int x = 0, y = 0, p = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'F') {
                    tx = i;
                    ty = j;
                } else if (grid[i][j] == 'M') {
                    x = i;
                    y = j;
                } else if (grid[i][j] == 'C') {
                    p = i;
                    q = j;
                }
            }
        }
        return dfs(x, y, p, q, 0) == 0;
    }
};