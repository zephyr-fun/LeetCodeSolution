// 2022.09.30
class Solution {
public:
    int getIdx(int x, int y, int m) {
        return x * m + y;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<int> que;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    que.push(getIdx(i, j, m));
                }
            }
        }
        while(!que.empty()) {
            int x = que.front() / m;
            int y = que.front() % m;
            que.pop();
            for(int i = 0; i < n; i++) {
                matrix[i][y] = 0;
            }
            for(int j = 0; j < m; j++) {
                matrix[x][j] = 0;
            }
        }
    }
};
// optim space https://leetcode.cn/problems/zero-matrix-lcci/solution/ling-ju-zhen-by-leetcode-solution-7ogg/