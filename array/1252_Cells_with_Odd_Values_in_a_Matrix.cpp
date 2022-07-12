// 2022.07.12
// plain solution
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(auto indice : indices) {
            int row = indice[0];
            int col = indice[1];
            for(int j = 0; j < m; j++) {
                grid[row][j] += 1;
            }
            for(int i = 0; i < n; i++) {
                grid[i][col] += 1;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] & 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

// 容斥原理
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        long long row = 0;
        long long col = 0;
        for(auto indice : indices) {
            row ^= (long long)1 << indice[0];
            col ^= (long long)1 << indice[1];
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i < n; i++) {
            if(row & ((long long)1 << i)) {
                a++;
            }
        }
        for(int i = 0; i < m; i++) {
            if(col & ((long long)1 << i)) {
                b++;
            }
        }
        return a * (m - b) + b * (n - a);
    }
};