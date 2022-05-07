// 2022.05.07
class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[i][j] refers to the minimum time of using j egg to find the F floor in a i floor building
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0x3f3f3f3f));
        // init
        for(int j = 1; j <= k; j++) {
            dp[1][j] = 1;
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }
        dp[0][0] = 0;
        // dp[i][j] = min_{x{1->i}}(max(dp[x - 1][j - 1], dp[i - x][j]))
        // f(x) = max(f_1(x), f_2(x))
        // f_1(x) = dp[x - 1][j - 1], monotonically increasing with x
        // f_2(x) = dp[i - x][j], monotonically decreasing with x
        // so the figure of f(x) looks like a "V"
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= k; j++) {
                int left = 1;
                int right = i;
                while(left < right) {
                    int mid = left + (right - left + 1) / 2;
                    int breakCount = dp[mid - 1][j - 1];
                    int notBreakCount = dp[i - mid][j];
                    if(breakCount > notBreakCount) {
                        right = mid - 1;
                    }
                    else {
                        left = mid;
                    }
                }
                dp[i][j] = max(dp[left - 1][j - 1], dp[i - left][j]) + 1;
            }
        }
        return dp[n][k];
    }
};