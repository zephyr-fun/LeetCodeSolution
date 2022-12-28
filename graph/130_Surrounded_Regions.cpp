// 2022.12.28
// flood fill
class Solution {
public:
    int n;
    int m;
    vector<vector<char>> board;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void solve(vector<vector<char>>& _board) {
        board = _board;
        n = board.size();
        if(!n) {
            return ;
        }
        m = board[0].size();
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0);
            }
            if(board[i][m - 1] == 'O') {
                dfs(i, m - 1);
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') {
                dfs(0, i);
            }
            if(board[n - 1][i] == 'O') {
                dfs(n - 1, i);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '@') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
        _board = board;
    }
    void dfs(int x, int y) {
        board[x][y] = '@';
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                dfs(nx, ny);
            }
        }
    }
};