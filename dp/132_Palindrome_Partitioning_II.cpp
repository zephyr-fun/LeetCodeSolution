// 2022.08.23
// preprocess the palindrome
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, 0));
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j) {
                    f[i][j] = true;
                }
                else if(j - i + 1 == 2) {
                    f[i][j] = s[i] == s[j];
                }
                else {
                    f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
                }
            }
        }
        vector<int> dp(n, 0x3f3f3f3f);
        for(int j = 0; j < n; j++) {
            if(f[0][j]) {
                dp[j] = 0;
            }
            else {
                for(int i = j; i > 0; i--) {
                    if(f[i][j]) {
                        dp[j] = min(dp[j], dp[i - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};