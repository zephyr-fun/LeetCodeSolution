// 2022.12.29
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int bfs(const vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        int n = forest.size();
        int m = forest[0].size();
        if(sx == tx && sy == ty) {
            return 0;
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> que;
        que.push(make_pair(sx, sy));
        vis[sx][sy] = true;
        int step = 0;
        while(!que.empty()) {
            int size = que.size();
            step++;
            for(int i = 0; i < size; i++) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = x + dirs[j][0];
                    int ny = y + dirs[j][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if(vis[nx][ny] || forest[nx][ny] == 0) {
                        continue;
                    }
                    if(nx == tx && ny == ty) {
                        return step;
                    }
                    que.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();
        vector<pair<int, int>> trees;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(forest[i][j] > 1) {
                    trees.emplace_back(make_pair(i, j));
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        int res = 0;
        int cx = 0;
        int cy = 0;
        for(auto& tree : trees) {
            int step = bfs(forest, cx, cy, tree.first, tree.second);
            if(step == -1) {
                return -1;
            }
            res += step;
            cx = tree.first;
            cy = tree.second;
        }
        return res;
    }
};