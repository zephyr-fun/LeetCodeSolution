// 2023.03.03
class Solution {
public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        int dp[n + 1][2][3];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> dfs = [&] (int u, int acnt, int lcnt) {
            if(acnt >= 2 || lcnt >= 3) {
                return 0;
            }
            if(u == 0) {
                return 1;
            }
            if(dp[u][acnt][lcnt] != -1) {
                return dp[u][acnt][lcnt];
            }
            int res = 0;
            res = dfs(u - 1, acnt + 1, 0) % mod; // A
            res = (res + dfs(u - 1, acnt, lcnt + 1)) % mod; // L
            res = (res + dfs(u - 1, acnt, 0)) % mod; // P
            dp[u][acnt][lcnt] = res;
            return res;
        };
        return dfs(n, 0, 0);
    }
};