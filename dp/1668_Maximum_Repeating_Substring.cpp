// 2022.11.22
// 序列DP
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        int res = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(i - m < 0) {
                continue;
            }
            if(sequence.substr(i - m, m) == word) {
                dp[i] = dp[i - m] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};