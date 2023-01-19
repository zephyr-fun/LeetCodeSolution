// 2022.04.09
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

// 2022.05.03
class Solution {
public:
    int integerBreak(int n) {
        // dp[i] refers to the maximum of time result of breaking i
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

// 2023.01.19
// https://leetcode.cn/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) {
            return n - 1;
        }
        int a = n / 3;
        int b = n % 3;
        if(b == 0) {
            return pow(3, a);
        }
        else if(b == 1) {
            return pow(3, a - 1) * 4;
        }
        return pow(3, a) * 2;
    }
};