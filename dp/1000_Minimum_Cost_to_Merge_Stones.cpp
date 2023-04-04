// 2023.04.04
// congratulations on 1k solutions !
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n - 1) % (k - 1)) {
            return -1;
        }
        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + stones[i];
        }
        int dp[n][n][k + 1];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> dfs = [&] (int i, int j, int p) -> int {
            int& res = dp[i][j][p];
            if(res != -1) {
                return res;
            }
            if(p == 1) {
                return res = i == j ? 0 : dfs(i, j, k) + preSum[j + 1] - preSum[i];
            }
            res = 0x3f3f3f3f;
            for(int m = i; m < j; m += k - 1) {
                res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            }
            return res;
        };
        return dfs(0, n - 1, 1);
    }
};