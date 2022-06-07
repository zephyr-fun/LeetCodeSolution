// 2022.06.07
// binary search + bfs
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid_;
    int n_;
    int swimInWater(vector<vector<int>>& grid) {
        grid_ = grid;
        int maxHeight = 0;
        int n = grid.size();
        n_ = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
        }
        int left = 0;
        int right = maxHeight;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(flood(mid)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
    bool flood(int depth) {
        vector<vector<bool>> visit(n_, vector<bool>(n_, false));
        queue<pair<int, int>> que;
        if(depth < grid_[0][0]) {
            return false;
        }
        que.emplace(0, 0);
        visit[0][0] = true;
        while(!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for(int k = 0; k < 4; k++) {
                int nextI = i + dirs[k][0];
                int nextJ = j + dirs[k][1];
                if(nextI < 0 || nextI >= n_ || nextJ < 0 || nextJ >= n_) {
                    continue;
                }
                if(grid_[nextI][nextJ] > depth || visit[nextI][nextJ] == true) {
                    continue;
                }
                visit[nextI][nextJ] = true;
                que.emplace(nextI, nextJ);
            }
        }
        return visit[n_ - 1][n_ - 1];
    }
};