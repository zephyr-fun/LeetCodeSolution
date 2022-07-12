// 2022.05.27
// BFS + State Compression
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = 1 << n;
        vector<vector<int>> dist(mask, vector<int>(n, 0x3f3f3f3f));
        queue<vector<int>> que;
        for(int i = 0; i < n; i++) {
            dist[1 << i][i] = 0;
            que.push({1 << i, i});
        }
        while(!que.empty()) {
            int state = que.front()[0];
            int u = que.front()[1];
            int step = dist[state][u];
            que.pop();
            if(state == mask - 1) {
                return step;
            }
            for(int i = 0; i < graph[u].size(); i++) {
                if(dist[state | (1 << graph[u][i])][graph[u][i]] == 0x3f3f3f3f) {
                    dist[state | (1 << graph[u][i])][graph[u][i]] = step + 1;
                    que.push({state | (1 << graph[u][i]), graph[u][i]});
                }
            }
        }
        return -1;
    }
};

// yxc version
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), INF = 1e8;
        vector<vector<int>> f(1 << n, vector<int>(n, INF));
        typedef pair<int, int> PII;

        #define x first
        #define y second

        queue<PII> q;
        for (int i = 0; i < n; i ++ ) {
            int x = 1 << i, y = i;
            f[x][y] = 0;
            q.push({x, y});
        }

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (auto z: graph[t.y]) {
                int a = t.x | 1 << z, b = z;
                if (f[a][b] > f[t.x][t.y] + 1) {
                    f[a][b] = f[t.x][t.y] + 1;
                    q.push({a, b});
                }
            }
        }

        int res = INF;
        for (int i = 0; i < n; i ++ )
            res = min(res, f[(1 << n) - 1][i]);
        return res;
    }
};

// topo dp
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, 0x3f3f3f3f));
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
            que.push({1 << i, i});
        }
        while(!que.empty()) {
            auto [state, u] = que.front();
            que.pop();
            for(auto v : graph[u]) {
                int nstate = state | (1 << v);
                if(dp[nstate][v] > dp[state][u] + 1) { // note + 1
                    dp[nstate][v] = dp[state][u] + 1;
                    que.push({nstate, v});
                }
            }
        }
        int res = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            res = min(res, dp[(1 << n) - 1][i]);
        }
        return res;
    }
};