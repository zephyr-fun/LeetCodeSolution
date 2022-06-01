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
