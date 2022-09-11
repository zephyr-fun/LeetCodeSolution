// 2022.09.11
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + fruits[i - 1][1];
        }
        vector<int> pos(n, 0);
        for(int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
        }
        // [l, r]
        int res = 0;
        for(int x = k; x >= 0; x--) {
            int y = (k - x) / 2;
            int l = startPos - x;
            int r = startPos + y;
            auto pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            auto pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = max(res, sum[pr] - sum[pl]);
            l = startPos - y;
            r = startPos + x;
            pl = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            pr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = max(res, sum[pr] - sum[pl]);
        }
        return res;
    }
};