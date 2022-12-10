// 2022.07.20
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = k % (n * m);
        int row = k / m;
        int col = k % m;
        if(k == 0) {
            return grid;
        }
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[row][col] = grid[i][j];
                if(col == m - 1) {
                    col = (col + 1) % m;
                    row = (row + 1) % n;
                }
                else {
                    col = col + 1;
                }
            }
        }
        return res;
    }
};

// 2022.12.10
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = k % (n * m);
        if(k == 0) {
            return grid;
        }
        int temp[n * m];
        memset(temp, 0, sizeof(temp));
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[idx++] = grid[i][j];
            }
        }
        idx = n * m - k;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = temp[idx];
                idx = (idx + 1) % (n * m);
            }
        }
        return grid;
    }
};