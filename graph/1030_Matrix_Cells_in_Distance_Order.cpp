// 2022.09.02
// bfs
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> res;
        queue<pair<int, int>> que;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        vis[rCenter][cCenter] = true;
        que.push({rCenter, cCenter});
        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            res.emplace_back(initializer_list<int>{x, y});
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || vis[nx][ny]) {
                    continue;
                }
                vis[nx][ny] = true;
                que.push({nx, ny});
            }
        }
        return res;
    }
};