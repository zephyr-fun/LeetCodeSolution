// 2022.04.04
class Solution {
public:
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string>& path, int n){
        // column
        for(int i = 0; i < row; i++){
            if(path[i][col] == 'Q'){
                return false;
            }
        }
        // 45
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(path[i][j] == 'Q'){
                return false;
            }
        }
        // 135
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(path[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& path){
        if(row == n){
            res.push_back(path);
            return ;
        }
        for(int col = 0; col < n; col++){
            if(isValid(row, col, path, n)){
                path[row][col] = 'Q';
                backtracking(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        backtracking(n, 0, path);
        return res;
    }
};

// 2022.04.05
class Solution {
public:
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string>& path, int n){
        for(int i = 0; i < row; i++){
            if(path[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >=0; i--, j--){
            if(path[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >=0 && j < n; i--, j++){
            if(path[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& path){
        if(row == n){
            res.push_back(path);
            return ;
        }
        for(int col = 0; col < n; col++){
            if(isValid(row, col, path, n)){
                path[row][col] = 'Q';
                backtracking(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        backtracking(n, 0, path);
        return res;
    }
};

// 2022.08.20
// no call
class Solution {
public:
    vector<bool> diagA;
    vector<bool> diagB;
    vector<bool> col;
    vector<vector<string>> res;
    vector<string> path;
    int n;
    void backtrack(int num) {
        if(num == n) {
            res.emplace_back(path);
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(!col[i] && !diagA[num - i + n - 1] && !diagB[num + i]) {
                path[num][i] = 'Q';
                col[i] = true;
                diagA[num - i + n - 1] = true;
                diagB[num + i] = true;
                backtrack(num + 1);
                path[num][i] = '.';
                col[i] = false;
                diagA[num - i + n - 1] = false;
                diagB[num + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        diagA.resize(2 * n - 1, false);
        diagB.resize(2 * n - 1, false);
        col.resize(n, false);
        path.resize(n, string(n, '.'));
        backtrack(0);
        return res;
    }
};

// with call
class Solution {
public:
    vector<bool> diagA;
    vector<bool> diagB;
    vector<bool> col;
    vector<vector<string>> res;
    vector<string> path;
    int n;
    bool check(int i, int j) {
        if(!col[j] && !diagA[i - j + n - 1] && !diagB[i + j]) {
            return true;
        }
        return false;
    }
    void backtrack(int num) {
        if(num == n) {
            res.emplace_back(path);
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(check(num, i)) {
                path[num][i] = 'Q';
                col[i] = true;
                diagA[num - i + n - 1] = true;
                diagB[num + i] = true;
                backtrack(num + 1);
                path[num][i] = '.';
                col[i] = false;
                diagA[num - i + n - 1] = false;
                diagB[num + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        diagA.resize(2 * n - 1, false);
        diagB.resize(2 * n - 1, false);
        col.resize(n, false);
        path.resize(n, string(n, '.'));
        backtrack(0);
        return res;
    }
};