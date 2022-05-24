// 2022.05.24
class Solution {
public:
    int countArrangement(int n) {
        int mask = 1 << n;
        // dp[i][state] refers to considering first i num, with selecting state, total plan
        vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int state = 0; state < mask; state++) {
                for(int k = 1; k <= n; k++) {
                    if((state & (1 << (k - 1))) == 0) {
                        continue;
                    }
                    if(k % i != 0 && i % k != 0) {
                        continue;
                    }
                    dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))];
                }
            }
        }
        return dp[n][mask - 1];
    }
};

// optim i dim
class Solution {
public:
    int getCnt(int state) {
        int cnt = 0;
        while(state != 0) {
            int lowbit = state & (-state);
            cnt++;
            state -= lowbit;
        }
        return cnt;
    }
    int countArrangement(int n) {
        int mask = 1 << n;
        // dp[state] refers to considering first i num, with selecting state, total plan
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int state = 0; state < mask; state++) {
                if(getCnt(state) != i) {
                    continue;
                }
                for(int k = 1; k <= n; k++) {
                    if((state & (1 << (k - 1))) == 0) {
                        continue;
                    }
                    if(k % i != 0 && i % k != 0) {
                        continue;
                    }
                    dp[state] += dp[state & (~(1 << (k - 1)))];
                }
            }
        }
        return dp[mask - 1];
    }
};

// optim
class Solution {
public:
    int getCnt(int state) {
        int cnt = 0;
        while(state != 0) {
            int lowbit = state & (-state);
            cnt++;
            state -= lowbit;
        }
        return cnt;
    }
    int countArrangement(int n) {
        int mask = 1 << n;
        // dp[state] refers with selecting state, total plan
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        for(int state = 1; state < mask; state++) {
            int cnt = getCnt(state);
            for(int k = 1; k <= n; k++) {
                if((state & (1 << (k - 1))) == 0) {
                    continue;
                }
                if(k % cnt != 0 && cnt % k != 0) {
                    continue;
                }
                dp[state] += dp[state & (~(1 << (k - 1)))];
            }
        }
        return dp[mask - 1];
    }
};