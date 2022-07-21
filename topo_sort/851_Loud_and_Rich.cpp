// 2022.07.21
// memo search
class Solution {
public:
    vector<vector<int>> g;
    vector<int> res;
    vector<int> w;
    void dfs(int u) {
        if(res[u] != -1) {
            return ;
        }
        res[u] = u;
        for(auto v : g[u]) {
            dfs(v);
            if(w[res[u]] > w[res[v]]) {
                res[u] = res[v];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        w = quiet;
        g.resize(n);
        res.resize(n, -1);
        for(auto rich : richer) {
            g[rich[1]].emplace_back(rich[0]);
        }
        for(int i = 0; i < n; i++) {
            dfs(i);
        }
        return res;
    }
};

// topo sort
