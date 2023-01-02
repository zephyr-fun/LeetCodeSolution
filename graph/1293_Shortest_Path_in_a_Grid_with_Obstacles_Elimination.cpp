// 2023.01.02
// key point : 1. class State 2. vis[n][m][k + 1]
class State {
public:
    int x;
    int y;
    int rest;
    State(int _x, int _y, int _rest) : x(_x), y(_y), rest(_rest) {}
};
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(k > m + n - 3) {
            return m + n - 2;
        }
        bool vis[n][m][k + 1];
        memset(vis, false, sizeof(vis));
        vis[0][0][k] = true;
        queue<State> que;
        que.emplace(0, 0, k);
        int step = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                int x = que.front().x;
                int y = que.front().y;
                int rest = que.front().rest;
                que.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = x + dirs[j][0];
                    int ny = y + dirs[j][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if(grid[nx][ny] == 0 && !vis[nx][ny][rest]) {
                        if(nx == n - 1 && ny == m - 1) {
                            return step + 1;
                        }
                        vis[nx][ny][rest] = true;
                        que.emplace(nx, ny, rest);
                    }
                    else if(grid[nx][ny] == 1 && rest > 0 && !vis[nx][ny][rest - 1]) {
                        vis[nx][ny][rest - 1] = true;
                        que.emplace(nx, ny, rest - 1);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};