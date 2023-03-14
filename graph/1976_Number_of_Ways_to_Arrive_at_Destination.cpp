// 2023.03.14
// https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/solution/by-ac_oier-4ule/
const long inf = 1e15, mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for(const auto& r : roads) {
            auto u = r[0], v = r[1], w = r[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<bool> vis(n, false);
        vector<long> dist(n, inf), dp(n, 0L);
        // dijkstra
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
        pq.push({0L, 0});
        dist[0] = 0;
        dp[0] = 1;
        while(!pq.empty()) {
            auto [_, u] = pq.top();
            pq.pop();
            if(vis[u]) {
                continue;
            }
            vis[u] = true;
            for(auto& [v, w] : g[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    dp[v] = dp[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == dist[u] + w) {
                    dp[v] = (dp[v] + dp[u]) % mod;
                }
            }
        }
        return dp[n - 1];
    }
};