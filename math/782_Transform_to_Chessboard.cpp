// 2022.08.23
// yxc version
class Solution {
public:
    const int INF = 1e8;

    int get_count(int x) {
        int res = 0;
        while (x) res += x & 1, x >>= 1;
        return res;
    }

    int get(int a, int b) {
        if (get_count(a) != get_count(b)) return INF;
        return get_count(a ^ b) / 2;
    }

    int movesToChessboard(vector<vector<int>>& board) {
        set<int> row, col;
        int n = board.size();
        for (int i = 0; i < n; i ++ ) {
            int r = 0, c = 0;
            for (int j = 0; j < n; j ++ ) {
                r = r << 1 | board[i][j];
                c = c << 1 | board[j][i];
            }
            row.insert(r), col.insert(c);
        }
        if (row.size() != 2 || col.size() != 2) return -1;
        int r1 = *row.begin(), r2 = *row.rbegin();
        int c1 = *col.begin(), c2 = *col.rbegin();
        if ((r1 ^ r2) != (1 << n) - 1 || (c1 ^ c2) != (1 << n) - 1) return -1;
        int s1 = 0;
        for (int i = 0; i < n; i += 2) s1 |= 1 << i;
        int s2 = ((1 << n) - 1) ^ s1;
        int r_cost = min(get(r1, s1), get(r1, s2));
        int c_cost = min(get(c1, s1), get(c1, s2));
        int res = r_cost + c_cost;
        if (res >= INF) return -1;
        return res;
    }
};