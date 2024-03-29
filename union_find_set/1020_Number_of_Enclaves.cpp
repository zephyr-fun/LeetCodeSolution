// 2022.06.21
// unionfindset
class UnionFindSet {
public:
    UnionFindSet(int n):rank(n + 1, 0), parent(n + 1, 0) {
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
    vector<int> rank;
    vector<int> parent;
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int SP = n * m;
        UnionFindSet set(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    set.Union(i * m + j, SP);
                    }
                    if(i + 1 < n && grid[i + 1][j] == 1) {
                        set.Union(i * m + j, (i + 1) * m + j);
                    }
                    if(j + 1 < m && grid[i][j + 1] == 1) {
                        set.Union(i * m + j, i * m + (j + 1));
                    }
                }
                
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && set.Find(i * m + j) != set.Find(n * m)) {
                    res++;
                }
            }
        }
        return res;
    }
};

// 2022.07.16
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 7, 0), rank(n + 7, 0) {
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
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        UnionFindSet set(n * m);
        int maxVal = n * m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        set.Union(getIdx(i, j, m), maxVal);
                    }
                    if(i + 1 < n && grid[i + 1][j] == 1) {
                        set.Union(getIdx(i + 1, j, m), getIdx(i, j, m));
                    }
                    if(j + 1 < m && grid[i][j + 1] == 1) {
                        set.Union(getIdx(i, j + 1, m), getIdx(i, j, m));
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && set.Find(getIdx(i, j, m)) != set.Find(maxVal)) {
                    res++;
                }
            }
        }
        return res;
    }
};