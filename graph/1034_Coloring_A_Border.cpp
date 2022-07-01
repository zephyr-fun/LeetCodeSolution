// 2022.07.01
// bfs
class Solution {
public:
    int n;
    int m;
    int getIdx(int row, int col) {
        return row * m + col;
    }
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        queue<int> que;
        que.push(getIdx(row, col));
        while(!que.empty()) {
            int idx = que.front();
            que.pop();
            int x = idx / m;
            int y = idx % m;
            bool flag = false;  // int cnt = 0
            for(int i = 0; i < 4; i++) {
                int nextX = x + dirs[i][0];
                int nextY = y + dirs[i][1];
                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                    continue;
                }
                if(grid[nextX][nextY] != grid[x][y]) { // or cnt++;
                    flag = true;
                    continue;
                }
                if(res[nextX][nextY]) {
                    continue;
                }
                que.push(getIdx(nextX, nextY));
            }
            if(flag || x == 0 || x == n - 1 || y == 0 || y == m - 1) { // res[x][y] = cnt == 4 ? grid[x][y] : color
                res[x][y] = color;
            }
            else {
                res[x][y] = grid[x][y];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = grid[i][j];
                }
            }
        }
        return res;
    }
};

// dfs
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> res;
    vector<vector<int>> grid;
    int color;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int x, int y) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(grid[x][y] != grid[nx][ny]) {
                continue;
            }
            cnt++;
            if(res[nx][ny] != 0) {
                continue;
            }
            res[nx][ny] = -1; // make sure we dont cnt it twice
            dfs(nx, ny);
        }
        res[x][y] = cnt == 4 ? grid[x][y] : color;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid_, int row, int col, int color_) {
        color = color_;
        grid = grid_;
        n = grid.size();
        m = grid[0].size();
        res.resize(n, vector<int>(m, 0));
        dfs(row, col);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = grid[i][j];
                }
            }
        }
        return res;
    }
};

// bfs repeat
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
    int m;
    vector<vector<int>> grid;
    vector<vector<int>> res;
    int color;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid_, int row, int col, int color_) {
        grid = grid_;
        color = color_;
        n = grid.size();
        m = grid[0].size();
        res.resize(n, vector<int>(m, 0));
        queue<pair<int, int>> que;
        que.push({row, col});
        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            int cnt = 0;
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(grid[x][y] != grid[nx][ny]) {
                    continue;
                }
                cnt++;
                if(res[nx][ny] != 0) {
                    continue;
                }
                que.push({nx, ny});
            }
            res[x][y] = cnt == 4 ? grid[x][y] : color;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = grid[i][j];
                }
            }
        }
        return res;
    }
};

// dfs repeat
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
    int m;
    vector<vector<int>> grid;
    vector<vector<int>> res;
    int color;
    void dfs(int x, int y) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(grid[x][y] != grid[nx][ny]) {
                continue;
            }
            cnt++;
            if(res[nx][ny] != 0) {
                continue;
            }
            res[nx][ny] = -1;
            dfs(nx, ny);
        }
        res[x][y] = cnt == 4 ? grid[x][y] : color;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid_, int row, int col, int color_) {
        grid = grid_;
        color = color_;
        n = grid.size();
        m = grid[0].size();
        res.resize(n, vector<int>(m, 0));
        dfs(row, col);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(res[i][j] == 0) {
                    res[i][j] = grid[i][j];
                }
            }
        }
        return res;
    }
};