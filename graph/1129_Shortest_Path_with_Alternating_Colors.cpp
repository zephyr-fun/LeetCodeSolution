// 2023.02.02
// bfs
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> g(2, vector<vector<int>>(n, vector<int>()));
        for(auto& edge : redEdges) {
            g[0][edge[0]].emplace_back(edge[1]);
        }
        for(auto& edge : blueEdges) {
            g[1][edge[0]].emplace_back(edge[1]);
        }
        vector<int> res(n, -1);
        bool vis[n][2];
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));
        que.push(make_pair(0, 1));
        int step = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [u, c] = que.front();
                que.pop();
                if(res[u] == -1) {
                    res[u] = step;
                }
                vis[u][c] = true;
                c ^= 1;
                for(auto& v : g[c][u]) {
                    if(!vis[v][c]) {
                        que.push(make_pair(v, c));
                    }
                }
            }
            step++;
        }
        return res;
    }
};