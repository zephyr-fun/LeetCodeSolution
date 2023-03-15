// 2023.03.15
// 定义 dp[i][j] 为从 (i, j)出发的， 到达所有边境的所有路径中的最大值的最小值
// 拆解为，首先找每条路径上的最大值，即能够挡住水从 (i, j) 流出的挡板，然后根据木桶理论，短板为决定条件
// sanye version
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct Cmp {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; i++) {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, m - 1, heightMap[i][m - 1]});
            vis[i][0] = vis[i][m - 1] = true;
        }
        for(int j = 0; j < m; j++) {
            pq.push({0, j, heightMap[0][j]});
            pq.push({n - 1, j, heightMap[n - 1][j]});
            vis[0][j] = vis[n - 1][j] = true;
        }
        int res = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            auto x = cur[0];
            auto y = cur[1];
            auto h = cur[2];
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(vis[nx][ny]) {
                    continue;
                }
                if(h > heightMap[nx][ny]) {
                    res += h - heightMap[nx][ny];
                }
                pq.push({nx, ny, max(h, heightMap[nx][ny])});
                vis[nx][ny] = true;
            }
        }
        return res;
    }
};

// yxc version
// struct is much faster
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct cell {
        int x, y, h;
        bool operator< (const cell& t) const {
            return h > t.h;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(!n || !m) {
            return 0;
        }
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        priority_queue<cell> pq;
        for(int i = 0; i < n; i++) {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, m - 1, heightMap[i][m - 1]});
            vis[i][0] = vis[i][m - 1] = true;
        }
        for(int j = 1; j < m - 1; j++) {
            pq.push({0, j, heightMap[0][j]});
            pq.push({n - 1, j, heightMap[n - 1][j]});
            vis[0][j] = vis[n - 1][j] = true;
        }
        int res = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.h - heightMap[cur.x][cur.y];
            for(int i = 0; i < 4; i++) {
                int nx = cur.x + dirs[i][0];
                int ny = cur.y + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
                    continue;
                }
                pq.push({nx, ny, max(cur.h, heightMap[nx][ny])});
                vis[nx][ny] = true;
            }
        }
        return res;
    }
};