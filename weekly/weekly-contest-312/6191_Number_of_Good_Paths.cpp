// 2022.09.25
// TLE
class Solution {
public:
    vector<int> vals;
    vector<vector<int>> tree;
    int res = 0;
    void dfs(int idx, int parent, int up) {
        if(vals[idx] == up) {
            res++;
        }
        for(auto& next : tree[idx]) {
            if(next == parent) {
                continue;
            }
            if(vals[next] > up) {
                continue;
            }
            dfs(next, idx, up);
        }
    }
    int numberOfGoodPaths(vector<int>& vals_, vector<vector<int>>& edges) {
        vals = vals_;
        int n = vals.size();
        tree.resize(n, vector<int>());
        for(auto& edge : edges) {
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, -1, vals[i]);
        }
        return (res - n) / 2 + n;
    }
};

// union find set
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1), rank(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> grid(n);
        for(auto& edge : edges) {
            grid[edge[0]].emplace_back(edge[1]);
            grid[edge[1]].emplace_back(edge[0]);
        }
        vector<int> q(n);
        for(int i = 0; i < n; i++) {
            q[i] = i;
        }
        sort(q.begin(), q.end(), [&](int& a, int& b) {
            return vals[a] < vals[b];
        });
        UnionFindSet set(n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n && vals[q[i]] == vals[q[j]]) {
                j++;
            }
            for(int k = i; k < j; k++) {
                int u = q[k];
                for(auto& v : grid[u]) {
                    if(vals[u] >= vals[v]) {
                        set.Union(u, v);
                    }
                }
            }
            unordered_map<int, int> map;
            for(int k = i; k < j; k++) {
                map[set.Find(q[k])]++;
            }
            for(auto& [k, v] : map) {
                res += v * (v + 1) / 2;
            }
            i = j - 1; // cause in the for loop i will ++
        }
        return res;
    }
};