// 2022.10.25
class Solution {
public:
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    void dfs(int i, int j, vector<pair<int,int>>& vec, vector<vector<int>>& grid) {
        if(grid[i][j] == 1) {
            vec.push_back(pair(i, j));
            grid[i][j] = 2;
        } 
        else {
            return;
        }
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(check(x, y)) {
                dfs(x, y, vec, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<pair<int,int>> vec1;
        vector<pair<int,int>> vec2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(vec1.size() == 0) {
                        dfs(i, j, vec1, grid);
                    } 
                    else {
                        dfs(i, j, vec2, grid);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < vec1.size(); i++) {
            for(int j = 0; j < vec2.size(); j++) {
                ans = min(ans, abs(vec2[j].first - vec1[i].first) + abs(vec2[j].second - vec1[i].second) - 1);
            }
        }
        return ans;
    }
};