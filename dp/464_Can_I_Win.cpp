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