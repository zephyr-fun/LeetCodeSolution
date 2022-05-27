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