// 2022.05.31
// floyd
class Solution {
public:
    const static int N = 107;
    const static int M = 6007;
    int w[N][N];
    int INF = 0x3f3f3f3f;
    int _n;
    int _k;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        _n = n;
        _k = k;
        // init
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                w[i][j] = w[j][i] = i == j ? 0 : INF;
            }
        }
        // build
        for(auto& time : times) {
            int u = time[0];
            int v = time[1];
            w[u][v] = time[2];
        }
        // floyd
        floyd();

        // traversal
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = max(res, w[k][i]);
        }
        return res >= INF / 2 ? -1 : res;
    }
    void floyd() {
        // floyd The basic flow is a three-level loop.
        // enumerate staging point - enumerate start point - enumerate end point - slack operation
        for(int p = 1; p <= _n; p++) {
            for(int i = 1; i <= _n; i++) {
                for(int j = 1; j <= _n; j++) {
                    w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
                }
            }
        }
    }
};

// plain Dijkstra


// 2022.12.27
// https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                grid[i][j] = i == j ? 0 : 0x3f3f3f3f;
            }
        }
        for(auto& time : times) {
            int u = time[0];
            int v = time[1];
            int cost = time[2];
            grid[u][v] = cost;
        }
        floyd(grid);
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = max(res, grid[k][i]);
        }
        return res >= 0x3f3f3f3f / 2 ? -1 : res;
    }
    void floyd(vector<vector<int>>& grid) {
        for(int p = 0; p < grid.size(); p++) {
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid.size(); j++) {
                    grid[i][j] = min(grid[i][j], grid[i][p] + grid[p][j]);
                }
            }
        }
    }
};

// 2023.03.12
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int g[n + 1][n + 1];
        memset(g, 0x3f, sizeof(g));
        for(int i = 1; i <= n; i++) {
            g[i][i] = 0;
        }
        for(auto& time : times) {
            g[time[0]][time[1]] = time[2];
        }
        function<void()> floyd = [&] () {
            // the order matters, you should enumerate the middle point first
            for(int k = 1; k <= n; k++) {
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        };
        floyd();
        int res = -0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            res = max(res, g[k][i]);
        }
        return res >= 0x3f3f3f3f / 2 ? -1 : res;
    }
};