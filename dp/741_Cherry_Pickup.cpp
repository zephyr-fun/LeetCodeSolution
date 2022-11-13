// 2022.07.11
// dp same with acwing 275, 1027
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // int N = 57;
        int inf = -0x3f3f3f3f;
        int n = grid.size();
        // k means step, i1 means row1, i2 means row2
        // we can get col1, col2 with k, i1, i2
        // col1 = k - i1, col2 = k - i2
        vector<vector<vector<int>>> dp(2 * (n + 1), vector<vector<int>>(n + 1, vector<int>(n + 1, inf)));
        dp[2][1][1] = grid[0][0];
        for(int k = 3; k <= 2 * n; k++) {
            for(int i1 = 1; i1 <= n; i1++) {
                for(int i2 = 1; i2 <= n; i2++) {
                    int j1 = k - i1;
                    int j2 = k - i2;
                    if(j1 > n || j1 <= 0 || j2 > n || j2 <= 0) {
                        continue;
                    }
                    int A = grid[i1 - 1][j1 - 1];
                    int B = grid[i2 - 1][j2 - 1];
                    if(A == -1 || B == -1) {
                        continue;
                    }
                    int a = dp[k - 1][i1 - 1][i2 - 1];
                    int b = dp[k - 1][i1][i2 - 1];
                    int c = dp[k - 1][i1 - 1][i2];
                    int d = dp[k - 1][i1][i2];
                    int t = max(max(a, b), max(c, d)) + A;
                    if(i1 != i2) {
                        t += B;
                    }
                    dp[k][i1][i2] = t;
                }
            }
        }
        return dp[2 * n][n][n] <= 0 ? 0 : dp[2 * n][n][n];
    }
};

// spfa, hard to understand
const int N = 35010, M = N * 8 + 10, INF = 1e8;
int h[N], e[M], f[M], w[M], ne[M], idx;
int q[N], d[N], pre[N], incf[N];
bool st[N];
int n, k, S, T;

class Solution {
public:
    int get(int x, int y, int t) {
        return (x * n + y) * 2 + t;
    }

    void add(int a, int b, int c, int d) {
        e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
        e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
    }    

    bool spfa() {
        memset(d, -0x3f, sizeof d);
        memset(incf, 0, sizeof incf);
        int hh = 0, tt = 1;
        q[0] = S, d[S] = 0, incf[S] = INF;
        
        while (hh != tt) {
            int t = q[hh++];
            if (hh == N) hh = 0;
            st[t] = false;
            
            for (int i = h[t]; ~i; i = ne[i]) {
                int ver = e[i];
                if (d[ver] < d[t] + w[i] && f[i]) {
                    d[ver] = d[t] + w[i];
                    pre[ver] = i;
                    incf[ver] = min(incf[t], f[i]);
                    if (!st[ver]) {
                        st[ver] = true;
                        q[tt++] = ver;
                        if (tt == N) tt = 0;
                    }
                }
            }
        }
        
        return incf[T] > 0;
    }

    void EK(int &flow, int &cost) {
        flow = 0, cost = 0;
        while (spfa()) {
            int t = incf[T];
            flow += t, cost += t * d[T];
            for (int i = T; i != S; i = e[pre[i] ^ 1]) {
                f[pre[i]] -= t;
                f[pre[i] ^ 1] += t;
            }
        }
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(h, -1, sizeof h);
        n = grid.size();
        k = 2;
        S = 2 * n * n, T = S + 1;

        add(S, get(0, 0, 0), k, 0);
        add(get(n - 1, n - 1, 1), T, k, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int c = grid[i][j];
                if (c == -1) continue;
                add(get(i, j, 0), get(i, j, 1), 1, c);
                add(get(i, j, 0), get(i, j, 1), INF, 0);
                if (i + 1 < n) add(get(i, j, 1), get(i + 1, j, 0), INF, 0);
                if (j + 1 < n) add(get(i, j, 1), get(i, j + 1, 0), INF, 0);
            }
        
        int flow, cost;
        EK(flow, cost);

        return cost;
    }
};

// 2022.11.13
const int N = 57;
int dp[N][N][2 * N];
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -0x3f, sizeof(dp));
        if(grid[0][0] != -1) {
            dp[1][1][2] = grid[0][0];
        }
        for(int step = 3; step <= 2 * n; step++) {
            for(int i = max(1, step - n); i <= min(n, step - 1); i++) {
                for(int j = max(1, step - n); j <= min(n, step - 1); j++) {
                    if(grid[i - 1][step - i - 1] == -1 || grid[j - 1][step - j - 1] == -1) {
                        continue;
                    }
                    int t = grid[i - 1][step - i - 1];
                    if(i != j) {
                        t += grid[j - 1][step - j - 1];
                    }
                    for(int a = i - 1; a <= i; a++) {
                        for(int b = j - 1; b <= j; b++) {
                            dp[i][j][step] = max(dp[i][j][step], dp[a][b][step - 1] + t);
                        }
                    }
                }
            }
        }
        return max(0, dp[n][n][2 * n]);
    }
};