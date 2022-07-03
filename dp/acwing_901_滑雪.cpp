// 2022.07.03
#include<iostream>
#include<vector>

using namespace std;

const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> dp;
vector<vector<int>> grid;
int n;
int m;
int dfs(int x, int y) {
    int& v = dp[x][y];
    if(v != -1) {
        return v;
    }
    v = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[x][y] < grid[nx][ny]) {
            v = max(v, dfs(nx, ny) + 1);
        }
    }
    return v;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    grid.resize(n, vector<int>(m, 0));
    dp.resize(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int res = -0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res = max(res, dfs(i, j));
        }
    }
    cout << res;
    return 0;
}