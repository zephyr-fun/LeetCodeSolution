// 2022.10.16
// https://www.acwing.com/video/3028/
// https://www.acwing.com/activity/content/code/content/1248145/
// 染色法
class Solution {
public:
    vector<vector<int>> grid;
    vector<int> color;

    bool dfs(int u, int c) {
        color[u] = c;
        for(auto& v : grid[u]) {
            if(color[v]) {
                if(color[v] == c) {
                    return false;
                }
            }
            else if(!dfs(v, 3 - c)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        grid.resize(n);
        color.resize(n);
        for(auto& d : dislikes) {
            grid[d[0] - 1].emplace_back(d[1] - 1);
            grid[d[1] - 1].emplace_back(d[0] - 1);
        }
        for(int i = 0; i < n; i++) {
            if(!color[i] && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }
};

// union find set
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1), rank(n + 1) {
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

    bool query(int u, int v) {
        return Find(u) == Find(v);
    }
private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        UnionFindSet set(2 * n);
        for(auto& d : dislikes) {
            int a = d[0];
            int b = d[1];
            if(set.query(a, b)) {
                return false;
            }
            set.Union(a, b + n);
            set.Union(b, a + n);
        }
        return true;
    }
};