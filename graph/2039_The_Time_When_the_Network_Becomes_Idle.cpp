// 2023.04.04
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> grid(n);
        for(auto& edge : edges) {
            grid[edge[0]].emplace_back(edge[1]);
            grid[edge[1]].emplace_back(edge[0]);
        }
        vector<bool> vis(n, false);
        queue<int> que;
        que.push(0);
        vis[0] = true;
        int res = -1;
        int d = 1;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                int cur = que.front();
                que.pop();
                for(auto& next : grid[cur]) {
                    if(vis[next]) {
                        continue;
                    }
                    int t = patience[next];
                    if(2 * d % patience[next]) {
                        t = 2 * d % patience[next];
                    }
                    res = max(4 * d - t + 1, res);
                    que.push(next);
                    vis[next] = true;
                }
            }
            d++;
        }
        return res;
    }
};