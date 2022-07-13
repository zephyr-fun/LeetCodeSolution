// 2022.07.13
class Solution {
public:
    int n = 2;
    int m = 3;
    string start;
    string end;
    int x;
    int y;
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int x, int y) {
        return x * 3 + y;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        start = "";
        end = "123450";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
                if(board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        int res = bfs();
        return res;
    }
    string update(string s, int cx, int cy, int nx, int ny) {
        int cidx = getIdx(cx, cy);
        int nidx = getIdx(nx, ny);
        char temp = s[cidx];
        s[cidx] = s[nidx];
        s[nidx] = temp;
        return s;
    }
    int bfs() {
        queue<pair<string, int>> que;
        unordered_map<string, int> map;
        que.push({start, getIdx(x, y)});
        map[start] = 0;
        while(!que.empty()) {
            auto [state, idx] = que.front();
            que.pop();
            int step = map[state];
            if(state == end) {
                return step;
            }
            int cx = idx / 3;
            int cy = idx % 3;
            for(int i = 0; i < 4; i++) {
                int nx = cx + dirs[i][0];
                int ny = cy + dirs[i][1];
                if(nx < 0 || nx >= 2 || ny < 0 || ny >= 3) {
                    continue;
                }
                string nstate = update(state, cx, cy, nx, ny);
                if(map.count(nstate)) {
                    continue;
                }
                que.push({nstate, getIdx(nx, ny)});
                map[nstate] = step + 1;
            }
        }
        return -1;
    }
};