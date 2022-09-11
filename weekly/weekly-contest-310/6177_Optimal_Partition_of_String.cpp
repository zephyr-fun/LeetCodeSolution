// 2022.09.11
class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        vector<int> dp(n, 1);
        map[s[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(map.count(s[i])) {
                dp[i] = max(dp[map[s[i]]] + 1, dp[i - 1]);
            }
            else {
                dp[i] = dp[i - 1];
            }
            map[s[i]] = i;
        }
        return dp[n - 1];
    }
};