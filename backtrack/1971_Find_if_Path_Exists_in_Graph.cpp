// 2022.12.19
// dfs
class Solution {
public:
    vector<vector<int>> grid;
    vector<int> vis;
    int source;
    int destination;
    bool traversal(int cur) {
        if(cur == destination) {
            return true;
        }
        vis[cur] = 1;
        for(auto& v : grid[cur]) {
            if(!vis[v]) {
                if(traversal(v)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source_, int destination_) {
        vis.resize(n, 0);
        grid.resize(n);
        source = source_;
        destination = destination_;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            grid[u].emplace_back(v);
            grid[v].emplace_back(u);
        }
        return traversal(source);
    }
};

// UnionFindSet
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1, 0), rank(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(parent[u] != u) {
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
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    bool connected(int u, int v) {
        return Find(u) == Find(v);
    }

private:
    vector<int> parent;
    vector<int> rank;

};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFindSet set(n);
        for(auto& edge : edges) {
            set.Union(edge[0], edge[1]);
            if(set.connected(source, destination)) {
                return true;
            }
        }
        return false || source == destination;
    }
};