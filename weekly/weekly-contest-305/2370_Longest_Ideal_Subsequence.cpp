// 2022.08.07 contest 2022.08.15 update
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        unordered_map<int, int> map;
        vector<int> dp(n, 0);
        // dp[0] = 1;
        // map[s[0] - 'a'] = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j <= k; j++) {
                if(s[i] - 'a' + j <= 25 && map.count(s[i] - 'a' + j)) {
                    // cout << "po" << s[i] - 'a' + k
                    dp[i] = max(dp[i], dp[map[s[i] - 'a' + j]] + 1);
                }
                if(0 <= s[i] - 'a' - j && map.count(s[i] - 'a' - j)) {
                    dp[i] = max(dp[i], dp[map[s[i] - 'a' - j]] + 1);
                }
            }
            map[s[i] - 'a'] = i;
            res = max(res, dp[i]);
            // cout << dp[i] << endl;
        }
        return res;
    }
};