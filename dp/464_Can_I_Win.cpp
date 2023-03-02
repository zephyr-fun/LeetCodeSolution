// 2022.05.22
// Game Theory
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        vector<int> dp(1 << maxChoosableInteger, -1);
        return dfs(desiredTotal, 0, maxChoosableInteger, dp) == 1;
    }
    int dfs(int total, int state, int max, vector<int>& dp) {
        if(dp[state] != -1) {
            return dp[state];
        }
        for(int i = 0; i < max; i++) {
            if(((state >> i) & 1) == 1) {
                continue;
            }
            if(total <= i + 1) {
                return dp[state] = 1;
            }
            if(dfs(total - i - 1, state | (1 << i), max, dp) == 0) {
                return dp[state] = 1;
            }
        }
        return dp[state] = 0;
    }
};

// 2023.03.02
class Solution {
public:
    int t;
    int n;
    int dp[1 << 20];
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        t = desiredTotal;
        n = maxChoosableInteger;
        memset(dp, -1, sizeof(dp));
        if(t == 0) {
            return true;
        }
        if(n * (n + 1) / 2 < t) {
            return false;
        }
        return dfs(0, 0);
    }
    bool dfs(int tot, int state) {
        if(dp[state] != -1) {
            return dp[state];
        }
        for(int i = 0; i < n; i++) {
            if((state >> i) & 1) {
                continue;
            }
            if(tot + i + 1 >= t) {
                dp[state] = 1; // notice
                return true;
            }
            if(dfs(tot + i + 1, state | (1 << i)) == 0) {
                dp[state] = 1; // notice
                return true;
            }
        }
        dp[state] = 0;
        return false;
    }
};