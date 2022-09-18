// 2022.07.05
class UnionFindSet {
public:
    UnionFindSet(int n, vector<vector<int>>& grid) : rank(n + 1, 0), parent(n + 1, 0), size(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    size[i * grid.size() + j] = 1;
                }
            }
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
            size[pv] += size[pu];
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
            size[pu] += size[pv];
        }
        return true;
    }

    int getSize(int u) {
        int pu = Find(u);
        return size[pu];
    }
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
};
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int n) {
        return x * n + y;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        UnionFindSet set(n * n, grid);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(i + 1 < n && grid[i + 1][j] == 1) {
                        set.Union(getIdx(i, j, n), getIdx(i + 1, j, n));
                    }
                    if(j + 1 < n && grid[i][j + 1] == 1) {
                        set.Union(getIdx(i, j, n), getIdx(i, j + 1, n));
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> rootSet;
                    int temp = 1;
                    for(int k = 0; k < 4; k++) {
                        int ni = i + dirs[k][0];
                        int nj = j + dirs[k][1];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            if(!rootSet.count(set.Find(getIdx(ni, nj, n)))) {
                                rootSet.insert(set.Find(getIdx(ni, nj, n)));
                                temp += set.getSize(set.Find(getIdx(ni, nj, n)));
                            }
                        }
                    }
                    res = max(res, temp);
                }
            }
        }
        return res == 0 ? n * n : res;
    }
};

// 2022.09.18
class UnionFindSet {
public:
    UnionFindSet(int k, vector<vector<int>>& grid) : parent(k + 1), rank(k + 1, 0), size(k + 1){
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                parent[i * m + j] = i * m + j;
                if(grid[i][j] == 1) {
                    size[i * m + j] = 1;
                }
            }
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
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

};
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        UnionFindSet set(n * m, grid);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(i + 1 < n && grid[i + 1][j] == 1) {
                        set.Union(getIdx(i, j, m), getIdx(i + 1, j, m));
                    }
                    if(j + 1 < m && grid[i][j + 1] == 1) {
                        set.Union(getIdx(i, j, m), getIdx(i, j + 1, m));
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> root_set;
                    int temp = 1;
                    for(int k = 0; k < 4; k++) {
                        int ni = i + dirs[k][0];
                        int nj = j + dirs[k][1];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                            if(!root_set.count(set.Find(getIdx(ni, nj, m)))) {
                                root_set.insert(set.Find(getIdx(ni, nj, m)));
                                temp += set.getSize(getIdx(ni, nj, m));
                            }
                        }
                    }
                    res = max(res, temp);
                }
            }
        }
        return res == 0 ? n * m : res;
    }
};