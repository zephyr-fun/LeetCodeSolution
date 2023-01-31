// 2022.06.26
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || i + j == n - 1) {
                    if(grid[i][j] == 0) {
                        return false;
                    }
                }
                else {
                    if(grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// 2023.01.31
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((i == j || i + j == n - 1) && grid[i][j] == 0) {
                    return false;
                }
                else if(i != j && i + j != n - 1 && grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};