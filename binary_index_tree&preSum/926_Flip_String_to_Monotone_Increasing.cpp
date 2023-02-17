// 2022.06.11
// prefix sum
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n + 2, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
        }
        prefix[n + 1] = prefix[n];
        int res = 0x3f3f3f3f;
        for(int i = 1; i <= n + 1; i++) {
            int zero = prefix[i - 1] - prefix[0];
            int one = (n - i + 1) - (prefix[n] - prefix[i - 1]);
            // cout << zero << '|' << one << endl;
            res = min(res, zero + one);
        }
        return res;
    }
};

// dp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '0' ? 1 : 0;
        for(int i = 1; i < n; i++) {
            char c = s[i];
            dp[i][0] = dp[i - 1][0] + (c == '0' ? 0 : 1);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (c == '1' ? 0 : 1);
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

// 2023.02.17
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, 0x3f3f3f3f));
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '0' ? 1 : 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + (s[i] == '0' ? 0 : 1));
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '0' ? 1 : 0);
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};