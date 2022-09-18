// 2022.09.18
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1] + 1) {
                dp[i + 1] = dp[i] + 1;
            }
            else {
                dp[i + 1] = 1;
            }
            res = max(res, dp[i + 1]);
        }
        return res;
    }
};