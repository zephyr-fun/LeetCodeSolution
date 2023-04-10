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
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> aja(n);
        vector<int> in(n, 0);
        queue<int> que;
        vector<int> res(n);
        for(auto r : richer) {
            int rich = r[0];
            int poor = r[1];
            aja[rich].emplace_back(poor);
            in[poor]++;
        }
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        iota(res.begin(), res.end(), 0);
        while(!que.empty()) {
            int rich = que.front();
            que.pop();
            for(auto poor : aja[rich]) {
                if(quiet[res[rich]] < quiet[res[poor]]) {
                    res[poor] = res[rich];
                }
                in[poor]--;
                if(in[poor] == 0) {
                    que.push(poor);
                }
            }
        }
        return res;
    }
};

// 2023.04.10
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> aja(n);
        vector<int> in(n, 0);
        queue<int> que;
        vector<int> res(n);
        for(auto r : richer) {
            int rich = r[0];
            int poor = r[1];
            aja[rich].emplace_back(poor);
            in[poor]++;
        }
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        iota(res.begin(), res.end(), 0);
        while(!que.empty()) {
            int rich = que.front();
            que.pop();
            for(auto poor : aja[rich]) {
                if(quiet[res[rich]] < quiet[res[poor]]) {
                    res[poor] = res[rich];
                }
                in[poor]--;
                if(in[poor] == 0) {
                    que.push(poor);
                }
            }
        }
        return res;
    }
};