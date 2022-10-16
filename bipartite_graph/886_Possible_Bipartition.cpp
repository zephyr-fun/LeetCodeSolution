// 2022.10.16
// https://www.acwing.com/video/3028/
// https://www.acwing.com/activity/content/code/content/1248145/
class Solution {
public:
    vector<vector<int>> grid;
    vector<int> color;

    bool dfs(int u, int c) {
        color[u] = c;
        for(auto& v : grid[u]) {
            if(color[v]) {
                if(color[v] == c) {
                    return false;
                }
            }
            else if(!dfs(v, 3 - c)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        grid.resize(n);
        color.resize(n);
        for(auto& d : dislikes) {
            grid[d[0] - 1].emplace_back(d[1] - 1);
            grid[d[1] - 1].emplace_back(d[0] - 1);
        }
        for(int i = 0; i < n; i++) {
            if(!color[i] && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }
};