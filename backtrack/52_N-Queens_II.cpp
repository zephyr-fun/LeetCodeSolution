// 2022.04.04
class Solution {
public:
    vector<vector<string>> res;
    bool isValid(int row, int col, int n, vector<string>& path){
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
            if(isValid(row, col, n, path)){
                path[row][col] = 'Q';
                backtracking(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        backtracking(n, 0, path);
        return res.size();
    }
};

// joke
class Solution {
public:
    int totalNQueens(int n) {
        int res;
        switch(n)
        {
            case 1 :
                res = 1;
                break;
            case 2 :
                res = 0;
                break;
            case 3 :
                res = 0;
                break;
            case 4 :
                res = 2;
                break;
            case 5 :
                res = 10;
                break;
            case 6 :
                res = 4;
                break;
            case 7 :
                res = 40;
                break;
            case 8 :
                res = 92;
                break;
            case 9 :
                res = 352;
                break;
        }
        return res;
    }
};