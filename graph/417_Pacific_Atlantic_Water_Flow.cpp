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

// 2022.07.27
// map may consume more space, set works as well
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        unordered_map<int, int> pmap;
        unordered_map<int, int> amap;
        queue<int> pque;
        queue<int> aque;
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    pque.push(getIdx(i, j, m));
                    pmap[getIdx(i, j, m)] = 0;
                }
                if(i == n - 1 || j == m - 1) {
                    aque.push(getIdx(i, j, m));
                    amap[getIdx(i, j, m)] = 0;
                }
            }
        }
        while(!pque.empty()) {
            int x = pque.front() / m;
            int y = pque.front() % m;
            int step = pmap[pque.front()];
            pque.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(pmap.count(getIdx(nx, ny, m))) {
                    continue;
                }
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || heights[x][y] > heights[nx][ny]) {
                    continue;
                }
                pque.push(getIdx(nx, ny, m));
                pmap[getIdx(nx, ny, m)] = step + 1;
            }
        }
        while(!aque.empty()) {
            int x = aque.front() / m;
            int y = aque.front() % m;
            int step = amap[aque.front()];
            aque.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(amap.count(getIdx(nx, ny, m))) {
                    continue;
                }
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || heights[x][y] > heights[nx][ny]) {
                    continue;
                }
                aque.push(getIdx(nx, ny, m));
                amap[getIdx(nx, ny, m)] = step + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int idx = getIdx(i, j, m);
                if(pmap.count(idx) && amap.count(idx)) {
                    res.emplace_back(initializer_list<int>{i, j});
                }
            }
        }
        return res;
    }
};