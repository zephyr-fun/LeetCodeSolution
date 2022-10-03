// 2022.09.24
// 逆序bfs TLE, 卡常吐了
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        queue<pair<int, int>> que;
        int layer = 0;
        // unordered_map<int, unordered_set<int>> set;
        
        vector<vector<int>> res;
        int n = plate.size();
        int m = plate[0].size();
        vector<vector<bool>> set(n * m + 7, vector<bool>(4, false));
        int a = 0;
        int b = getIdx(n - 1, 0, m);
        int c = getIdx(0, m - 1, m);
        int d = getIdx(n - 1, m - 1, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(plate[i][j] == 'O') {
                    for(int k = 0; k < 4; k++) {
                        int dir = k;
                        int ni = i + dirs[k][0];
                        int nj = j + dirs[k][1];
                        if(ni < 0 || ni >= n || nj < 0 || nj >= m) {
                            continue;
                        }
                        if(plate[ni][nj] == 'W') {
                            dir = (dir + 1) % 4;
                        }
                        else if(plate[ni][nj] == 'E') {
                            dir = (dir - 1 + 4) % 4;
                        }
                        // cout << "i:" << ni << "j:" << nj << "dir:" << dir << endl;
                        que.push(make_pair(getIdx(ni, nj, m), dir));
                        set[getIdx(ni, nj, m)][dir] = true;
                    }
                }
            }
        }
        while(layer < num && !que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto [idx, dir] = que.front();
                que.pop();
                int x = idx / m;
                int y = idx % m;
                if((x == 0 || x == n - 1 || y == 0 || y == m - 1) && plate[x][y] == '.') {
                    // cout << "x:" << x << "y:" << y << "dir:" << dir << endl;
                    int idx = getIdx(x, y, m);
                    if(idx == a || idx == b || idx == c || idx == d) {
                        continue;
                    }
                    if((x == 0 && dir == 0) || (x == n - 1 && dir == 2) || (y == 0 && dir == 3) || (y == m - 1 && dir == 1)) {
                        res.emplace_back(initializer_list<int>{x, y});
                    }
                }
                int nx = x + dirs[dir][0];
                int ny = y + dirs[dir][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(plate[nx][ny] == 'W') {
                    dir = (dir + 1) % 4;
                }
                else if(plate[nx][ny] == 'E') {
                    dir = (dir - 1 + 4) % 4;
                }
                if(set[getIdx(nx, ny, m)][dir]) {
                    continue;
                }
                que.push(make_pair(getIdx(nx, ny, m), dir));
                set[getIdx(nx, ny, m)][dir] = true;
            }
            layer++;
        }
        return res;
    }
};

// 1st solution
