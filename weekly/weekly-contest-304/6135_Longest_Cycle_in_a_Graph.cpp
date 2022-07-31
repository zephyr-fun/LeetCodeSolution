// 2022.07.31
class Solution {
public:
    int res = 0;
    vector<int> edges;
    vector<vector<int>> g;
    vector<int> in;
    vector<bool> vis;
    void dfs(int cur, int cnt) {
        if(!vis[cur]) {
            vis[cur] = true;
            dfs(edges[cur], cnt + 1);
        }
        else {
            res = max(res, cnt);
        }
    }
    int longestCycle(vector<int>& edges_) {
        edges = edges_;
        int n = edges.size();
        g.resize(n);
        in.resize(n, 0);
        vis.resize(n, false);
        for(int i = 0; i < n; i++) {
            if(edges[i] == -1) {
                continue;
            }
            g[i].emplace_back(edges[i]);
            in[edges[i]]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(auto next : g[cur]) {
                in[next]--;
                if(in[next] == 0) {
                    que.push(next);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i] != 0 && !vis[i]) {
                dfs(i, 0);
            }
        }
        return res == 0 ? -1 : res;
    }
};