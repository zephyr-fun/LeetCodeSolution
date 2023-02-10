// 2023.02.10
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int mod = 1e9 + 7;
        // [pos][last][continue] -> [i][j][k]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        for(int j = 0; j < 6; j++) {
            dp[0][j][1] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 6; j++) {
                for(int t = 0; t < 6; t++) {
                    if(j == t) {
                        for(int k = 2; k <= rollMax[j]; k++) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
                        }
                    }
                    else {
                        for(int k = 1; k <= rollMax[t]; k++) {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][t][k]) % mod;
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int j = 0; j < 6; j++) {
            for(int k = 1; k <= rollMax[j]; k++) {
                res = (res + dp[n - 1][j][k]) % mod;
            }
        }
        return res;
    }
};