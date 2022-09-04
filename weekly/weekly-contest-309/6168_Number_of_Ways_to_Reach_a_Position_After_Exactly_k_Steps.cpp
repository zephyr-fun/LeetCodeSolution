// 2022.09.04
// memory search
class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int offset = 1000;
    int dfs(int step, int pos) {
        if(dp[step][pos + offset] != -1) {
            return dp[step][pos + offset];
        }
        dp[step][pos + offset] = 0;
        if(step > 0) {
            dp[step][pos + offset] = (dp[step][pos + offset] + dfs(step - 1, pos - 1)) % mod;
            dp[step][pos + offset] = (dp[step][pos + offset] + dfs(step - 1, pos + 1)) % mod;
        }
        return dp[step][pos + offset];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        dp.resize(1e3 + 7, vector<int>(3007, -1));
        dp[0][startPos + offset] = 1;
        int res = dfs(k, endPos);
        return res;
    }
};

// dp
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>> dp(k + 1, vector<long long>(3007, 0));
        int mod = 1e9 + 7;
        int offset = 1000;
        dp[0][startPos + offset] = 1;
        for(int i = 1; i <= k; i++) {
            for(int j = startPos - offset; j <= startPos + offset; j++) {
                dp[i][j + offset] = (dp[i - 1][j + offset - 1] + dp[i - 1][j + offset + 1]) % mod;
            }
        }
        return dp[k][endPos + offset];
    }
};


// math
// tsreaper version
// https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/solution/by-tsreaper-qzp3/
class Solution {
    const int MOD = 1000000007;

public:
    int numberOfWays(int startPos, int endPos, int K) {
        int d = abs(startPos - endPos);
        if ((d + K) % 2 == 1 || d > K) return 0;
        // 递推求组合数
        vector<vector<long long>> f;
        f.resize(K + 1, vector<long long>(K + 1));
        for (int i = 0; i <= K; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= i; j++) f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
        }
        return f[K][(d + K) / 2];
    }
};

//求组合数，需要用到乘法逆元
class Solution {
    const int MOD = 1000000007;

public:
    int numberOfWays(int startPos, int endPos, int K) {
        int d = abs(startPos - endPos);
        if ((d + K) % 2 == 1 || d > K) return 0;
        // 线性求逆元
        vector<long long> inv(K + 1);
        inv[1] = 1;
        for (int i = 2; i <= K; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        // 递推求组合数，初值 C(k, 0) = 1
        long long ans = 1;
        for (int i = 1; i <= (d + K) / 2; i++) ans = ans * (K - i + 1) % MOD * inv[i] % MOD;
        return ans;
    }
};