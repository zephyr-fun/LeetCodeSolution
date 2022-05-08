// 2022.05.08
class Solution {
public:
    int mod = 1000000007;
    int countTexts(string pressedKeys) {
        // dp[i] refers to the posibility number until ith char
        int map[10];
        memset(map, 0, sizeof(map));
        for(int i = 2; i <= 6; i++) {
            map[i] = 3;
        }
        for(int i = 7; i <= 9; i++) {
            map[i] = 4;
        }
        map[8] = 3;
        vector<int> dp(pressedKeys.size() + 1, 0);
        dp[0] = 1;
        int nowLen = 1;
        for(int i = 1; i < pressedKeys.size(); i++) {
            int num = pressedKeys[i] - 48;
            // cout << num << endl;
            if(pressedKeys[i] == pressedKeys[i - 1]) {
                nowLen += 1;
                // cout << "+1nowlen" << nowLen << endl;
                if(nowLen > map[num]) {
                    for(int j = 1; j <= map[num]; j++) {
                        dp[i] += dp[i - j];
                        dp[i] %= mod;
                    }
                }
                else {
                    dp[i] = dp[i - 1] * 2;
                    dp[i] %= mod;
                }
            }
            else {
                nowLen = 1;
                // cout << "=1nowlen" << nowLen << endl;
                dp[i] = dp[i - 1];
            }
        }
        return dp[pressedKeys.size() - 1];
    }
};