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

// 2023.09.21
// 在 topo 的过程中更新结果，因为当前处理的总是从富有指向贫穷，这样就可以更新贫穷的结果
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> in(n, 0);
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);
        for (auto& r : richer) {
            // r[0] is richer than r[1]
            g[r[0]].emplace_back(r[1]);
            in[r[1]]++;
        }

        queue<int> que;

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto& v: g[u]) {
                if (quiet[res[u]] < quiet[res[v]]) {
                    res[v] = res[u];
                }
                if (--in[v] == 0) {
                    que.push(v);
                }
            }
        }
        return res;
    }
};