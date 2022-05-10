// 2022.05.10
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) {
                dp[j] = 0; // dont understand
                for(int t = 1; t <= k; t++) {
                    if(j >= t) {
                        dp[j] = (dp[j] + dp[j - t]) % mod;
                    }
                }
            }
        }
        return dp[target];
    }
};