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