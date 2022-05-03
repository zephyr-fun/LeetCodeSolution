// 2022.04.11
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// another order
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i * i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j - i * i >= 0){
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};

// 2022.05.03
// bag first
// item second
class Solution {
public:
    int numSquares(int n) {
        // dp[i] refers to the minimum of breaking i in to psn
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// item first
// bag second
class Solution {
public:
    int numSquares(int n) {
        // dp[i] refers to the minimum of breaking i in to psn
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int j = 1; j * j <= n; j++) {
            for(int i = 0; i <= n; i++) {
                if(i >= j * j){
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
};