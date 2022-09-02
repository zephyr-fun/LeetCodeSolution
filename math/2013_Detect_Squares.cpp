// 2022.09.02
// O(n^2), plain
class DetectSquares {
public:
    unordered_map<int, unordered_set<int>> row_map;
    unordered_map<int, unordered_set<int>> col_map;
    unordered_map<int, int> map;

    int getIdx(int x, int y) {
        return x + y * 2000;
    }

    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int row = point[0];
        int col = point[1];
        row_map[col].insert(row);
        col_map[row].insert(col);
        map[getIdx(row, col)]++;
    }
    
    int count(vector<int> point) {
        int row = point[0];
        int col = point[1];
        int res = 0;
        for(auto row_temp : row_map[col]) {
            for(auto col_temp : col_map[row]) {
                if(row_temp == row || col_temp == col) {
                    continue;
                }
                if(abs(row_temp - row) == abs(col_temp - col) && col_map.count(row_temp) && col_map[row_temp].count(col_temp)) {
                    res += map[getIdx(row_temp, col_temp)] * map[getIdx(row, col_temp)] * map[getIdx(row_temp, col)];
                }
            }
        }
        return res;
    }
};

// constrain
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int row = point[0];
        int col = point[1];
        cnt[col][row]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int row = point[0];
        int col = point[1];
        if(!cnt.count(col)) {
            return 0;
        }
        unordered_map<int, int>& row_Cnt = cnt[col];
        for(auto& [col_temp, colCnt] : cnt) {
            if(col_temp != col) {
                int len = col_temp - col;
                res += (colCnt.count(row) ? colCnt[row] : 0) * (row_Cnt.count(row + len) ? row_Cnt[row + len] : 0) * 
                       (colCnt.count(row + len)? colCnt[row + len] : 0);
                res += (colCnt.count(row) ? colCnt[row] : 0) * (row_Cnt.count(row - len) ? row_Cnt[row - len] : 0) * 
                       (colCnt.count(row - len) ? colCnt[row - len] : 0);
            }
        }
        return res;
    }
};