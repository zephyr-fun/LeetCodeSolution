// 2022.10.22
// L : ^ 2
// R : ^ 3
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int l[4] = {3, 2, 1, 0};
    int r[4] = {1, 0, 3 ,2};
    int n;
    int m;
    int res = 0;
    vector<string> grid;
    void dfs(int x, int y, int dir) {
        if(x < 0 || x >= n || y < 0 || y >= m) {
            return ;
        }
        res++;
        if(grid[x][y] == 'L') {
            dir = l[dir];
        }
        else if(grid[x][y] == 'R') {
            dir = r[dir];
        }
        dfs(x + dirs[dir][0], y + dirs[dir][1], dir);
    }
    int getLength(vector<string>& grid_) {
        grid = grid_;
        n = grid.size();
        m = grid[0].size();
        dfs(0, 0, 2);
        return res;
    }
};