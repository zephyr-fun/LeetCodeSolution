// 2022.11.08
// dp[i][j] refers to the minimum step of getting i chars with j chars in the paste
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        dp[1][0] = 0;
        dp[1][1] = 1;
        for(int i = 2; i <= n; i++) {
            int minVal = 0x3f3f3f3f;
            for(int j = 0; j <= i / 2; j++) {
                dp[i][j] = dp[i - j][j] + 1;
                minVal = min(minVal, dp[i][j]);
            }
            dp[i][i] = minVal + 1;
        }
        int res = 0x3f3f3f3f;
        for(int i = 0; i <= n; i++) {
            res = min(res, dp[n][i]);
        }
        return res;
    }
};

// math
// k1 + k2 + ... + kx = res
// k1 * k2 * ... * kx = n
// a * b >= a + b
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i * i <= n; i++) {
            while(n % i == 0) {
                res += i;
                n /= i;
            }
        }
        if(n != 1) {
            res += n;
        }
        return res;
    }
};