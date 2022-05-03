// 2022.04.09
// recursion
class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

// dp
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// dp optim space
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

// 2022.05.03
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// optim space
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[0] = dp[0] + dp[1];
            dp[0] ^= dp[1];
            dp[1] ^= dp[0];
            dp[0] ^= dp[1];
        }
        return dp[1];
    }
};