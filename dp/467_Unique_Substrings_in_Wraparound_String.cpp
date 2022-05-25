class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // dp[a] refers to with a as the last letter, the string length
        vector<int> dp(26, 0);
        int k = 0;
        for(int i = 0; i < p.size(); i++) {
            if(i && ((p[i] - p[i - 1] + 26) % 26 == 1)) {
                k++;
            }
            else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(k, dp[p[i] - 'a']); // only record the max length
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};