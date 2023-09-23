// 2022.07.12
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1, 0), rank(n + 1, 0) {
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
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        UnionFindSet set(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0') {
                    continue;
                }
                if(i + 1 < n && grid[i + 1][j] == '1') {
                    set.Union(getIdx(i, j, m), getIdx(i + 1, j, m));
                }
                if(j + 1 < m && grid[i][j + 1] == '1') {
                    set.Union(getIdx(i, j, m), getIdx(i, j + 1, m));
                }
            }
        }
        unordered_set<int> cnt;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0') {
                    continue;
                }
                cnt.insert(set.Find(getIdx(i, j, m)));
            }
        }
        return cnt.size();
    }
};

// 2023.09.23
// 2-dim Union Find Set
typedef pair<int, int> pii;
static int n;
static int m;
class UnionFindSet {
public:
    UnionFindSet(vector<vector<char>>& grid) : parent(n, vector<pii>(m)), rank(n, vector<int>(m, 0)), size(n, vector<int>(m, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    size[i][j] = 1;
                    parent[i][j] = make_pair(i, j);
                }
            }
        }
    }

    pii Find(int x, int y) {
        if (x != parent[x][y].first || y != parent[x][y].second) {
            parent[x][y] = Find(parent[x][y].first, parent[x][y].second);
        }
        return parent[x][y];
    }

    bool Union(int x1, int y1, int x2, int y2) {
        auto [p1x, p1y] = Find(x1, y1);
        auto [p2x, p2y] = Find(x2, y2);
        if (p1x == p2x && p1y == p2y) {
            return false;
        }
        if (rank[p1x][p1y] < rank[p2x][p2y]) {
            parent[p1x][p1y] = make_pair(p2x, p2y);
            size[p2x][p2y] += size[p1x][p1y];
        }
        else if (rank[p1x][p1y] > rank[p2x][p2y]) {
            parent[p2x][p2y] = make_pair(p1x, p1y);
            size[p1x][p1y] += size[p2x][p2y];
        }
        else {
            parent[p2x][p2y] = make_pair(p1x, p1y);
            size[p1x][p1y] += size[p2x][p2y];
            rank[p1x][p1y]++;
        }
        return true;
    }

private:
    vector<vector<pii>> parent;
    vector<vector<int>> rank;
    vector<vector<int>> size;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        UnionFindSet set(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n && grid[i][j] == '1' && grid[i + 1][j] == '1') {
                    set.Union(i, j, i + 1, j);
                }
                if (j + 1 < m && grid[i][j] == '1' && grid[i][j + 1] == '1') {
                    set.Union(i, j, i, j + 1);
                }
            }
        }
        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    auto [x, y] = set.Find(i, j);
                    res.insert(x * m + y);
                }
            }
        }
        return res.size();
    }
};