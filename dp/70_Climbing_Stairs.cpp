// 2022.04.09
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};
//继续深化，就是一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) { // 代码中m表示最多可以爬m个台阶, 把m换成2，就可以AC爬楼梯这道题
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};

// 2022.04.11
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int m = 2;
        for(int j = 0; j <= n; j++){
            for(int i = 1; i <= m; i++){
                if(i <= j){
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};

// 2022.05.03
class Solution {
public:
    int climbStairs(int n) {
        // dp[i] refers to the nums of ways to get to ith stairs
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// optim space
class Solution {
public:
    int climbStairs(int n) {
        // dp[i] refers to the nums of ways to get to ith stairs
        if(n <= 2) {
            return n;
        }
        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 3; i <= n; i++) {
            dp[0] = dp[0] + dp[1];
            dp[0] ^= dp[1];
            dp[1] ^= dp[0];
            dp[0] ^= dp[1];
        }
        return dp[1];
    }
};