// 2023.05.08
typedef vector<int> VI;
const int N = 20;
int dist[N][N][N][N];
bool st[N][N][N][N];
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        VI start(4);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'B') {
                    start[0] = i;
                    start[1] = j;
                }
                else if(grid[i][j] == 'S') {
                    start[2] = i;
                    start[3] = j;
                }
            }
        }
        deque<VI> dq;
        dq.push_back(start);
        memset(dist, 0x3f, sizeof(dist));
        memset(st, 0, sizeof(st));
        dist[start[0]][start[1]][start[2]][start[3]] = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!dq.empty()) {
            auto t = dq.front();
            dq.pop_front();
            if(st[t[0]][t[1]][t[2]][t[3]]) {
                continue;
            }
            st[t[0]][t[1]][t[2]][t[3]] = true;
            int distance = dist[t[0]][t[1]][t[2]][t[3]];
            if(grid[t[0]][t[1]] == 'T') {
                return distance;
            }
            for(int i = 0; i < 4; i++) {
                int x = t[2] + dx[i];
                int y = t[3] + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && (x != t[0] || y != t[1]) && dist[t[0]][t[1]][x][y] > distance) {
                    dist[t[0]][t[1]][x][y] = distance;
                    dq.push_front({t[0], t[1], x, y});
                }
                if(t[0] - t[2] == dx[i] && t[1] - t[3] == dy[i]) {
                    x = t[0] + dx[i];
                    y = t[1] + dy[i];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && dist[x][y][t[0]][t[1]] > distance + 1) {
                        dist[x][y][t[0]][t[1]] = distance + 1;
                        dq.push_back({x, y, t[0], t[1]});
                    }
                }
            }
        }
        return -1;
    }
};