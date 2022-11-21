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

// 2022.11.21
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int maxLen[26];
        memset(maxLen, 0, sizeof(maxLen));
        int n = p.size();
        maxLen[p[0] - 'a']++;
        for(int i = 1, cnt = 1; i < n; i++) {
            int cur = p[i] - 'a';
            int prev = p[i - 1] - 'a';
            if((cur == 0 && prev == 25) || prev + 1 == cur) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            maxLen[cur] = max(maxLen[cur], cnt);
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            res += maxLen[i];
        }
        return res;
    }
};