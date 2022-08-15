// 2022.08.14 contest 2022.08.15 update
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                for(int x = i; x <= i + 2; x++) {
                    for(int y = j; y <= j + 2; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};