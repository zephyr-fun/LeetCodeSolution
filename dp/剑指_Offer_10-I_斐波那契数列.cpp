// 2022.08.08
class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = 1;
        if(n < 2) {
            return dp[n];
        }
        for(int i = 2; i <= n; i++) {
            dp[i % 2] = (dp[i % 2] + dp[(i + 1) % 2]) % mod;
        }
        return dp[n % 2];
    }
};