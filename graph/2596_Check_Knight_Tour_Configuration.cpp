// 2023.09.13
static const int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return false;
        }
        int n = grid.size();
        int m = grid[0].size();
        int cur = 0;
        int total = n * m;
        int curx = 0;
        int cury = 0;
        bool state = false;
        while (cur < total - 1) {
            cur++;
            state = false;
            // cout << curx << cury << cur << endl;
            for (int i = 0; i < 8; i++) {
                int nextx = curx + dirs[i][0];
                int nexty = cury + dirs[i][1];
                if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
                    continue;
                }
                if (grid[nextx][nexty] == cur) {
                    state = true;
                    curx = nextx;
                    cury = nexty;
                    break;
                }
            }
            if (!state) {
                return false;
            }
        }
        return true;
    }
};

// traversal
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return false;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> pos(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < n * m; i++) {
            auto [x1, y1] = pos[i - 1];
            auto [x2, y2] = pos[i];
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);
            bool state = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
            if (!state) {
                return false;
            }
        }
        return true;
    }
};