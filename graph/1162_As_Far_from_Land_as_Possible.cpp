// 2022.07.05
// single source bfs + loop
// O(n * n * n * n)
// TLE
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> grid;
    int n;
    int getIdx(int x, int y) {
        return x * n + y;
    }
    pair<int, int> getPos(int idx) {
        return {idx / n, idx % n};
    }
    int bfs(int sourceX, int sourceY) {
        queue<int> que;
        unordered_map<int, int> map;
        que.push(getIdx(sourceX, sourceY));
        map[getIdx(sourceX, sourceY)] = 0;
        while(!que.empty()) {
            auto [x, y] = getPos(que.front());
            int step = map[que.front()];
            que.pop();
            if(grid[x][y] == 1) {
                return step;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if(map.find(getIdx(nx, ny)) != map.end()) {
                    continue;
                }
                que.push(getIdx(nx, ny));
                map[getIdx(nx, ny)] = step + 1;
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid_) {
        grid = grid_;
        int res = -1;
        n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    res = max(res, bfs(i, j));
                }
            }
        }
        return res;
    }
};

// multi source bfs, through dummy single source
class Solution {
public:
    int getIdx(int x, int y, int n) {
        return x * n + y;
    }
    pair<int, int> getPos(int cur, int n) {
        return {cur / n, cur % n};
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<int> que;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    que.push(getIdx(i, j, n));
                    map[getIdx(i, j, n)] = 0;
                }
            }
        }
        int res = -1;
        while(!que.empty()) {
            auto [x, y] = getPos(que.front(), n);
            int step = map[que.front()];
            que.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if(grid[nx][ny] != 0) {
                    continue;
                }
                grid[nx][ny] = step + 1;
                map[getIdx(nx, ny, n)] = step + 1;
                que.push(getIdx(nx, ny, n));
                res = max(res, step + 1);
            }
        }
        return res;
    }
};