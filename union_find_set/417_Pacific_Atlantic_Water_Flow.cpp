// 2022.06.05
// bfs
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    int n;
    int m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> res1(n, vector<bool>(m, false));
        vector<vector<bool>> res2(n, vector<bool>(m, false));
        queue<pair<int, int>> que1;
        queue<pair<int, int>> que2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    res1[i][j] = true;
                    que1.emplace(i, j);
                }
                if(i == n - 1 || j == m - 1) {
                    res2[i][j] = true;
                    que2.emplace(i, j);
                }
            }
        }
        bfs(que1, res1, heights);
        bfs(que2, res2, heights);
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res1[i][j] && res2[i][j]) {
                    vector<int> temp = {i, j};
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
    void bfs(queue<pair<int, int>>& que, vector<vector<bool>>& res, vector<vector<int>>& heights) {
        while(!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for(auto dir : dirs) {
                int nextI = i + dir[0];
                int nextJ = j + dir[1];
                if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) {
                    continue;
                }
                if(res[nextI][nextJ] || heights[nextI][nextJ] < heights[i][j]) {
                    continue;
                }
                que.emplace(nextI, nextJ);
                res[nextI][nextJ] = true;
            }
        }
    }
};

// dfs
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    int n;
    int m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> res1(n, vector<bool>(m, false));
        vector<vector<bool>> res2(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    if(!res1[i][j]) {
                        dfs(i, j, res1, heights);
                    }
                }
                if(i == n - 1 || j == m - 1) {
                    if(!res2[i][j]) {
                        dfs(i, j, res2, heights);
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res1[i][j] && res2[i][j]) {
                    vector<int> temp = {i, j};
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<bool>>& res, vector<vector<int>>& heights) {
        res[i][j] = true;
        for(auto dir : dirs) {
            int nextI = i + dir[0];
            int nextJ = j + dir[1];
            if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) {
                continue;
            }
            if(res[nextI][nextJ] || heights[nextI][nextJ] < heights[i][j]) {
                continue;
            }
            dfs(nextI, nextJ, res, heights);
        }
    }
};

// union find set
// class UnionFindSet {
// public:
//     UnionFindSet(int n) {
//         _ranks = vector<int>(n + 1, 0);
//         _parent = vector<int>(n + 1, 0);
//         for(int i = 0; i < _parent.size(); i++) {
//             _parent[i] = i;
//         }
//     }

//     int Find(int u) {
//         if(u != _parent[u]) {
//             _parent[u] = Find(_parent[u]);
//         }
//         return _parent[u];
//     }

//     bool Union(int u, int v) {
//         int pu = Find(u);
//         int pv = Find(v);
//         if(pu == pv) {
//             return false;
//         }
//         if(_ranks[pu] < _ranks[pv]) {
//             _parent[pu] = pv;
//         }
//         else if(_ranks[pu] > _ranks[pv]) {
//             _parent[pv] = pu;
//         }
//         else {
//             _parent[pv] = pu;
//             _ranks[pu]++;
//         }
//     }
// private:
//     vector<int> _ranks;
//     vector<int> _parent;
// };

// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();
//         int tot = m * n;
//         int S = tot + 1;
//         int T = tot + 2;

//         vector<vector<bool>> res1(n, vector<bool>(m, false));
//         vector<vector<bool>> res2(n, vector<bool>(m, false));
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(i == 0 || j == 0) {
//                     if(!res1[i][j]) {
//                         dfs(i, j, res1, heights);
//                     }
//                 }
//                 if(i == n - 1 || j == m - 1) {
//                     if(!res2[i][j]) {
//                         dfs(i, j, res2, heights);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(res1[i][j] && res2[i][j]) {
//                     vector<int> temp = {i, j};
//                     res.emplace_back(temp);
//                 }
//             }
//         }
//         return res;
//     }
// };
// not fully understand
class Solution {
public:
    int m, n;
    vector<int> p1;
    vector<int> p2;
    int get_idex(int x, int y) {
        return x * n + y;
    }
    int find(vector<int>& parent, int idex) {
        if (parent[idex] != idex)
            parent[idex] = find(parent, parent[idex]);
        return parent[idex];
    }
    void Union(vector<int>& parent, int idex1, int idex2) {
        parent[find(parent, idex1)] = find(parent, idex2);
    }
    vector<int> direction{ -1,0,1,0,-1 };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        p1.resize(m * n + 1, 0);
        p2.resize(m * n + 1, 0);
        for (int i = 0; i <= m * n; ++i) {
            p1[i] = i;
            p2[i] = i;
        }
        for (int i = 0; i < m; ++i)
            if (find(p1, get_idex(i, 0)) != find(p1, m * n))
                dfs(i, 0, p1, heights);
        for (int i = 0; i < n; ++i)
            if (find(p1, get_idex(0, i)) != find(p1, m * n))
                dfs(0, i, p1, heights);
        for (int i = 0; i < m; ++i)
            if (find(p2, get_idex(i, n - 1)) != find(p2, m * n))
                dfs(i, n - 1, p2, heights);
        for (int i = 0; i < n; ++i)
            if (find(p2, get_idex(m - 1, i)) != find(p2, m * n))
                dfs(m - 1, i, p2, heights);

        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((find(p2, get_idex(i, j)) == find(p2, m * n)) && (find(p1, get_idex(i, j)) == find(p1, m * n)))
                    ret.push_back({ i,j });
            }
        }
        return ret;
    }
    void dfs(int x, int y, vector<int>& p, vector<vector<int>>& heights) {
        Union(p, get_idex(x, y), m * n);
        for (int i = 0; i < 4; ++i) {
            int dx = x + direction[i];
            int dy = y + direction[i + 1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && heights[x][y] <= heights[dx][dy] && (find(p, get_idex(dx, dy)) != find(p, m * n))){
                dfs(dx, dy, p, heights);
            }
        }
    }
};

// 2022.06.18
// bfs
class Solution {
private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int n;
    int m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<bool> seenP(n * m, false);
        vector<bool> seenA(n * m, false);
        queue<pair<int, int>> queP;
        queue<pair<int, int>> queA;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    queP.emplace(i, j);
                    seenP[i * m + j] = true;
                }
                if(i == n - 1 || j == m - 1) {
                    queA.emplace(i, j);
                    seenA[i * m + j] = true;
                }
            }
        }
        fill(seenP, queP, heights);
        fill(seenA, queA, heights);
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(seenA[i * m + j] && seenP[i * m + j]) {
                    vector<int> temp;
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    // vector<int> temp = {i, j};
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
    void fill(vector<bool>& seen, queue<pair<int, int>>& que, vector<vector<int>>& heights) {
        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < n && nx >= 0 && ny < m && ny >= 0 && !seen[nx * m + ny] && heights[nx][ny] >= heights[x][y]) {
                    que.emplace(nx, ny);
                    seen[nx * m + ny] = true;
                }
            }
        }
    }
};

// UnionFindSet
// actually no need
class UnionFindSet {
public:
    UnionFindSet(int n): parent(n + 7, 0), rank(n + 7, 0) {
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
        else if(rank[pv] < rank[pu]) {
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
private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int n;
    int m;
    vector<vector<int>> heights_;
    void dfs(UnionFindSet& set, vector<vector<bool>>& res, int x, int y) {
        set.Union(x * m + y, n * m);
        res[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx < n && nx >= 0 && ny < m && ny >= 0 && !res[nx][ny] && heights_[x][y] <= heights_[nx][ny]) {
                dfs(set, res, nx, ny);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        heights_ = heights;
        n = heights.size();
        m = heights[0].size();
        UnionFindSet setP(n * m);
        UnionFindSet setA(n * m);
        vector<vector<bool>> res1(n, vector<bool>(m, false));
        vector<vector<bool>> res2(n, vector<bool>(m, false));
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0) && !res1[i][j]) {
                    dfs(setP, res1, i, j);
                }
                if((i == n - 1 || j == m - 1) && !res2[i][j]) {
                    dfs(setA, res2, i, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(setP.Find(i * m + j) == setP.Find(n * m) && setA.Find(i * m + j) == setA.Find(n * m)) {
                    vector<int> temp = {i, j};
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
};