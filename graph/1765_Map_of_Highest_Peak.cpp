// 2022.07.05
// multi source bfs
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int n) {
        return x * n + y;
    }
    pair<int, int> getPos(int cur, int n) {
        return {cur / n, cur % n};
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j]) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                    isWater[i][j] = 0;
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
                isWater[nx][ny] = step + 1;
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
            }
        }
        return isWater;
    }
};

// 2022.07.06
// optim give value
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    pair<int, int> getPos(int cur, int m) {
        return {cur / m, cur % m};
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                }
            }
        }
        while(!que.empty()) {
            auto [x, y] = getPos(que.front(), m);
            int step = map[que.front()];
            que.pop();
            isWater[x][y] = step;
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(map.find(getIdx(nx, ny, m)) != map.end()) {
                    continue;
                }
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
            }
        }
        return isWater;
    }
};

// 2022.07.14
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    pair<int, int> getPos(int cur, int m) {
        return {cur / m, cur % m};
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                }
            }
        }
        while(!que.empty()) {
            auto [x, y] = getPos(que.front(), m);
            int step = map[que.front()];
            que.pop();
            isWater[x][y] = step;
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(map.find(getIdx(nx, ny, m)) != map.end()) {
                    continue;
                }
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
            }
        }
        return isWater;
    }
};

// 2023.04.05
// 尽可能不要额外构建数据结构，节省空间和时间
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> que;
        int n = isWater.size();
        int m = isWater[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    que.push({i, j});
                    isWater[i][j] = -1;
                }
            }
        }
        int h = 1;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [x, y] = que.front();
                que.pop();
                for(int k = 0; k < 4; k++) {
                    int nx = x + dirs[k][0];
                    int ny = y + dirs[k][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || isWater[nx][ny] != 0) {
                        continue;
                    }
                    isWater[nx][ny] = h;
                    que.push({nx, ny});
                }
            }
            h++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == -1) {
                    isWater[i][j] = 0;
                }
            }
        }
        return isWater;
    }
};