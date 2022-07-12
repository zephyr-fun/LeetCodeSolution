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