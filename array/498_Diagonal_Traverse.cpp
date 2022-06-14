// 2022.06.14
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int dir = 1;
        int n = mat.size();
        int m = mat[0].size();
        int total = n * m;
        vector<int> res;
        int x = 0;
        int y = 0;
        while(total--) {
            res.push_back(mat[x][y]);
            if(dir == 1) {
                if(x - 1 < 0 || y + 1 >= m) {
                    if(y + 1 < m) {
                        y = y + 1;
                    }
                    else {
                        x = x + 1;
                    }
                    dir = -1;
                }
                else {
                    x = x - 1;
                    y = y + 1;
                }
            }
            else {
                if(x + 1 >= n || y - 1 < 0) {
                    if(x + 1 < n) {
                        x = x + 1;
                    }
                    else {
                        y = y + 1;
                    }
                    dir = 1;
                }
                else {
                    x = x + 1;
                    y = y - 1;
                }
            }
        }
        return res;
    }
};