// 2022.07.09
class UnionFindSet {
public:
    UnionFindSet(int n, vector<vector<int>>& grid) : parent(n + 1, 0), rank(n + 1, 0), size(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    size[i * grid[0].size() + j] = 1;
                }
            }
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
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
            rank[pu]++;
        }
        return true;
    }

    int getSize(int u) {
        int pu = Find(u);
        return size[pu];
    }
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};
class Solution {
public:
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        UnionFindSet set(n * m, grid);
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                res = max(res, set.getSize(getIdx(i, j, m)));
                if(i + 1 < n && grid[i + 1][j] == 1) {
                    if(set.Union(getIdx(i, j, m), getIdx(i + 1, j, m))) {
                        res = max(res, set.getSize(getIdx(i, j, m)));
                    }
                }
                if(j + 1 < m && grid[i][j + 1] == 1) {
                    if(set.Union(getIdx(i, j, m), getIdx(i, j + 1, m))) {
                        res = max(res, set.getSize(getIdx(i, j, m)));
                    }
                }
            }
        }
        return res;
    }
};