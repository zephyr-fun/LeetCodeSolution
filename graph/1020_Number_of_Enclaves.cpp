// 2022.06.06
// bfs
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    que.emplace(i, j);
                    visit[i][j] = true;
                }
            }
        }
        while(!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for(int k = 0; k < 4; k++) {
                auto dir = dirs[k];
                int nextI = i + dir[0];
                int nextJ = j + dir[1];
                if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) {
                    continue;
                }
                if(grid[nextI][nextJ] == 0 || visit[nextI][nextJ] == true) {
                    continue;
                }
                que.emplace(nextI, nextJ);
                visit[nextI][nextJ] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visit[i][j] == false && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

// dfs
class Solution {
public:
    vector<vector<int>> grids;
    int n;
    int m;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, vector<vector<bool>>& visit) {
        for(int k = 0; k < 4; k++) {
            auto dir = dirs[k];
            int nextI = i + dir[0];
            int nextJ = j + dir[1];
            if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) {
                continue;
            }
            if(grids[nextI][nextJ] == 0 || visit[nextI][nextJ] == true) {
                continue;
            }
            visit[nextI][nextJ] = true;
            dfs(nextI, nextJ, visit);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        grids = grid;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1)&& grid[i][j] == 1) {
                    visit[i][j] = true;
                    dfs(i, j, visit);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visit[i][j] == false && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};