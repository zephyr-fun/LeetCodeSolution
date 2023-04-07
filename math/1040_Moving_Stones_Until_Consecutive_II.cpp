// 2023.04.07
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        vector<int> res(2);
        int n = stones.size();
        sort(stones.begin(), stones.end());
        int m = stones.back() - stones[0] - (n - 1);
        res[1] = m - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);

        res[0] = n;
        for (int i = 0, j = 0; i < n; i ++ ) {
            while (stones[i] - stones[j] + 1 > n) {
                j++;
            }
            m = i - j + 1;
            int r;
            if(m == n - 1 && stones[i] - stones[j] == i - j) {
                r = 2;
            }
            else {
               r = n - m;
            }
            res[0] = min(res[0], r);
        }
        return res;
    }
};