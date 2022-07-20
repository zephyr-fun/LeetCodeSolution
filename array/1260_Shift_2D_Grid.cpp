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