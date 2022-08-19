// 2022.08.19
// plain
class Solution {
public:
    constexpr static int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n;
    int m;
    int len;
    vector<vector<char>> board;
    string word;
    string path;
    unordered_set<int> set;
    int getIdx(int i, int j, int m) {
        return i * m + j;
    }
    bool backtracking(int cur, int num) {
        int x = cur / m;
        int y = cur % m;
        if(board[x][y] != word[num]) {
            return false;
        }
        path += board[x][y];
        set.insert(cur);
        if(path == word) {
            return true;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(set.count(getIdx(nx, ny, m))) {
                continue;
            }
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(backtracking(getIdx(nx, ny, m), num + 1)) {
                    return true;
                }
            }
        }
        path.pop_back();
        set.erase(cur);
        return false;
    }
    bool exist(vector<vector<char>>& board_, string word_) {
        board = board_;
        word = word_;
        n = board.size();
        m = board[0].size();
        len = word.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(backtracking(getIdx(i, j, m),0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// optim
class Solution {
public:
    constexpr static int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n;
    int m;
    int len;
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    string word;
    bool backtracking(int x, int y, int num) {
        if(board[x][y] != word[num]) {
            return false;
        }
        if(num == len - 1) {
            return true;
        }
        vis[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
                continue;
            }
            if(backtracking(nx, ny, num + 1)) {
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board_, string word_) {
        board = board_;
        word = word_;
        n = board.size();
        m = board[0].size();
        len = word.size();
        vis.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(backtracking(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};