// 2023.02.05
// queue overflow on leetcode
// https://c.runoob.com/compile/12/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
class Solution {
    int dirs[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        // cout << n << endl;
        bool vis[n][n][2];
        memset(vis, 0, sizeof(vis));
        vis[0][0][0] = true;
        queue<tuple<int, int, int>> que;
        que.push({0, 0, 0});
        int step = 1;
        while(!que.empty()) {
            int size = que.size();
            // cout << size << endl;
            for(int i = 0; i < size; i++) {
                // auto& [curx, cury, curs] = que.front();
				int curx = std::get<0>(que.front());
				int cury = std::get<1>(que.front());
				int curs = std::get<2>(que.front());
                que.pop();
				cout << curx << cury << curs << endl;
                for(auto& dir : dirs) {
                    // cout << i << ',';
                    int nxtx = curx + dir[0];
                    int nxty = cury + dir[1];
                    int nxts = curs ^ dir[2];
                    int x2 = nxtx + nxts;
                    int y2 = nxty + (nxts ^ 1);
                    cout << size << i << endl;
                    cout << nxtx << ',' << nxty << "|" << x2 << ',' << y2 << '|' << nxts << '|' << step << endl;
                    if(x2 < n && y2 < n && !vis[nxtx][nxty][nxts] && grid[nxtx][nxty] == 0 && grid[x2][y2] == 0 && (dir[2] == 0 || grid[nxtx + 1][nxty + 1] == 0)) {
                        if(nxtx == n - 1 && nxty == n - 2) {
                            return step;
                        }
                        vis[nxtx][nxty][nxts] = true;
                        que.push({nxtx, nxty, nxts});
                    }
                }
                // cout << endl;
            }
            step++;
        }
        return -1;
    }
};
int main() {
    Solution* s = new Solution();
    vector<vector<int>> test = {{0,0,0,0,0,0,0,0,0,1},{1,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0},{0,0,1,0,1,1,1,0,0,0},{0,0,1,0,0,0,1,0,1,0},{0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0}};
    int res = s->minimumMoves(test);
	cout << res << "completed";
    return 0;
}

// use vector to replace queue
class Solution {
    int dirs[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        bool vis[n][n][2];
        memset(vis, 0, sizeof(vis));
        vis[0][0][0] = true;
        vector<tuple<int, int, int>> que = {{0, 0, 0}};
        for(int step = 1; !que.empty(); step++) {
            vector<tuple<int, int, int>> next;
            for(const auto& [curx, cury, curs] : que) {
                for(auto& dir : dirs) {
                    int nxtx = curx + dir[0];
                    int nxty = cury + dir[1];
                    int nxts = curs ^ dir[2];
                    int x2 = nxtx + nxts;
                    int y2 = nxty + (nxts ^ 1);
                    if(x2 < n && y2 < n && !vis[nxtx][nxty][nxts] && grid[nxtx][nxty] == 0 && grid[x2][y2] == 0 && (dir[2] == 0 || grid[nxtx + 1][nxty + 1] == 0)) {
                        if(nxtx == n - 1 && nxty == n - 2) {
                            return step;
                        }
                        vis[nxtx][nxty][nxts] = true;
                        next.emplace_back(nxtx, nxty, nxts);
                    }
                }
            }
            que = move(next);
        }
        return -1;
    }
};