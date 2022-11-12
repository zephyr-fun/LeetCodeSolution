// 2022.11.12
// https://leetcode.cn/problems/domino-and-tromino-tiling/solution/by-endlesscheng-umpp/
class Solution {
public:
    int numTilings(int n) {
        if(n == 1) {
            return 1;
        }
        int mod = 1e9 + 7;
        long dp[n + 1];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};

// optim space
class Solution {
    const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        if(n == 1) {
           return 1; 
        }
        long a = 1;
        long b = 1;
        long c = 2;
        for(int i = 3; i <= n; ++i) {
            long f = (c * 2 + a) % mod;
            a = b;
            b = c;
            c = f;
        }
        return c;
    }
};

// pre compute
const int mod = 1e9 + 7;
long dp[1001];
int init = []() {
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 1000; ++i) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int numTilings(int n) {
        return dp[n];
    }
};