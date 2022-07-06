// 2022.07.06
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    pair<int, int> getPos(int cur, int m) {
        return {cur / m, cur % m};
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                }
            }
        }
        while(!que.empty()) {
            auto [x, y] = getPos(que.front(), m);
            int step = map[que.front()];
            que.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(map.find(getIdx(nx, ny, m)) != map.end()) {
                    continue;
                }
                if(grid[nx][ny] == 0) {
                    map[getIdx(nx, ny, m)] = -1;
                    continue;
                }
                grid[nx][ny] = 2;
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
                res = max(res, step + 1);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};

// optim fresh count
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    pair<int, int> getPos(int cur, int m) {
        return {cur / m, cur % m};
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        int res = 0;
        int cnt = 0; // cnt fresh
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                }
                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        while(!que.empty()) {
            auto [x, y] = getPos(que.front(), m);
            int step = map[que.front()];
            que.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(map.find(getIdx(nx, ny, m)) != map.end()) {
                    continue;
                }
                if(grid[nx][ny] == 0) {
                    map[getIdx(nx, ny, m)] = -1;
                    continue;
                }
                cnt--; // consume fresh
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
                res = max(res, step + 1);
            }
        }
        return cnt == 0 ? res : -1;
    }
};