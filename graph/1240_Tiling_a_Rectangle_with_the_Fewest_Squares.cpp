// 2023.06.09
class Solution {
public:
    vector<vector<bool>> st;
    int res;
    int n;
    int m;

    bool check(int x, int y, int len) {
        for(int i = x; i < x + len; i++) {
            for(int j = y; j < y + len; j++) {
                if(st[i][j]) {
                    return false;
                }
            }    
        }    
        return true;
    }

    void fill(int x, int y, int len, bool t) {
        for(int i = x; i < x + len; i++) {
            for(int j = y; j < y + len; j++) {
                st[i][j] = t;
            }
        }
    }

    void dfs(int x, int y, int cnt) {
        if (cnt >= res) {
            return;  // 最优性剪枝
        }
        // 组合数优化
        if (y == m) {
            x++;
            y = 0;
        }
        if(x == n) {
            res = cnt;
        }
        else {
            if(st[x][y]) {
                dfs(x, y + 1, cnt);
            }
            else {
                // 搜索顺序优化
                for(int len = min(n - x, m - y); len; len--) {
                    if(check(x, y, len)) {
                        fill(x, y, len, true);
                        dfs(x, y + len, cnt + 1);
                        fill(x, y, len, false);
                    }
                }
            }
        }
    }

    int tilingRectangle(int n, int m) {
        res = n * m;
        this->n = n, this->m = m;
        st = vector<vector<bool>>(n, vector<bool>(m));
        dfs(0, 0, 0);
        return res;
    }
};