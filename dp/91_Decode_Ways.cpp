// 2022.07.07
class Solution {
public:
    int numDecodings(string s) {
        s = " " + s;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            int one = s[i] - '0';
            int two = (s[i - 1] - '0') * 10 + one;
            if(one >= 1 && one <= 9) {
                dp[i] = dp[i - 1];
            }
            if(two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};