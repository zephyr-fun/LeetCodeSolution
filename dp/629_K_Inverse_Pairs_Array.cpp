// 2022.07.09
// acwing sequence dp
// https://leetcode.cn/problems/k-inverse-pairs-array/solution/gong-shui-san-xie-yi-dao-xu-lie-dp-zhuan-tm01/
class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9 + 7;
        // dp[i][j] refers to num of considering 1->i with j inverse
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[1][0] = 1;
        for(int i = 2; i <= n; i++) {
            long long sum = 0;
            for(int j = 0; j <= k; j++) {
                sum += dp[i - 1][j];
                if(j - i >= 0) {
                    sum -= dp[i - 1][j - i];
                }
                dp[i][j] = sum % mod;
            }
        }
        return (dp[n][k] + mod) % mod;
    }
};