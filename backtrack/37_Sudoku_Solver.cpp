class Solution {
public:
    bool backtracking(vector<vector<char>>& board){
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if(board[row][col] != '.'){
                    continue;
                }
                for(char k = '1'; k <= '9'; k++){
                    if(isValid(row, col, k, board)){
                        board[row][col] = k;
                        if(backtracking(board)){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(int row, int col, char k, vector<vector<char>>board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == k){
                return false;
            }
        }
        for(int j = 0; j < 9; j++){
            if(board[j][col] == k){
                return false;
            }
        }
        int rowStart = (row / 3) * 3;
        int colStart = (col / 3) * 3;
        for(int i = rowStart; i < rowStart + 3; i++){
            for(int j = colStart; j < colStart + 3; j++){
                if(board[i][j] == k){
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// amazing
class Solution {
    private:
    int row[9];
    int col[9];
    int cel[3][3];
    vector<pair<int,int>> pos;
    bool val;
public:
    void filp(int i,int j ,int p){
        row[i]^=1<<(p);
        col[j]^=1<<(p);
        cel[i/3][j/3]^=1<<(p);
    }
    void dfs(vector<vector<char>>& board,int p){
        if(p == pos.size()){
            val = true;
            return;
        }
        auto [x,y] = pos[p];
        int mask = ~(row[x]|col[y]|cel[x/3][y/3])&0x1FF;
        for(;mask&&!val;mask&=(mask-1)){
            int mask1 = mask&(-mask);
            int dit = __builtin_ctz(mask1);
            filp(x,y,dit);
            board[x][y] = dit+1+'0';
            dfs(board,p+1);
            filp(x,y,dit);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        val = false;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(cel,0,sizeof(cel));


        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')
                    pos.push_back({i,j});
                else{
                    filp(i,j,board[i][j]-'0'-1);
                }
            }
        }
        dfs(board,0);
    }   
};

// bitset
class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);// expect for 'used nums' in rows and cols and cells
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10; // max equals to 9
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j); // find the least possible number  
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret; // position
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? 1 : 0; // change status in rows;
        cols[y][n] = (fillFlag) ? 1 : 0; // change status in cols;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0; // change status in cells;
    }
    
    bool backtracking(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (backtracking(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        backtracking(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};