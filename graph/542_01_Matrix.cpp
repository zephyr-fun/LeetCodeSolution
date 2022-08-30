// 2022.08.30
class Solution {
public:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int getIdx(int i, int j, int m) {
        return i * m + j;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<int> que;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    que.push(getIdx(i, j, m));
                    map[getIdx(i, j, m)] = 0;
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            int step = map[cur];
            que.pop();
            int x = cur / m;
            int y = cur % m;
            mat[x][y] = step;
            // cout << "x, y: " << x << y << endl;
            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                // cout << nx << ny << step + 1 << endl;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || map.count(getIdx(nx, ny, m))) {
                    continue;
                }
                // cout << "que push: " << nx << ny << step + 1 << endl;
                que.push(getIdx(nx, ny, m));
                map[getIdx(nx, ny, m)] = step + 1;
            }
        }
        return mat;
    }
};