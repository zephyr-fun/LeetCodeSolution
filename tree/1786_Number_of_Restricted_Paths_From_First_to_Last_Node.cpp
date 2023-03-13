// 2023.03.13
// 带堆优化的dijkstra + dp
const int inf = (1L << 31) - 1, mod = 1e9 + 7;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector G(n + 1, vector<pair<int,int>>{});
        vector dist(n + 1, inf), vis(n + 1, 0);
        for(const auto& e : edges) {
            G[e[0]].push_back( {e[1], e[2]} ), G[e[1]].push_back( {e[0], e[2]} );
        }
        //Dijkstra
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[n] = 1;
        pq.push( {0, n} );
        while(pq.size()) {
            auto [_, u] = pq.top();  pq.pop();
            for(auto& [v, w] : G[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push( {dist[v], v } ); 
                }
            }
        }
        //DP
        vector f(n + 1, 0);
        f[n] = 1;
        auto cmp = [&](auto u, auto v) {
            return dist[u] > dist[v];
        };
        //小根堆,保证dist距离小的先出队
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size()) {
            auto u = q.top(); q.pop();
            for(auto [v, _] : G[u]) {
                if(dist[v] > dist[u]) {
                    f[v] = (f[v] + f[u]) % mod;
                }
            }
        }
        return f[1];
    }
};