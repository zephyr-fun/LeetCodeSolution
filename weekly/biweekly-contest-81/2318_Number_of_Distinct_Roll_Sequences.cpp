// 2022.06.27
const int N = 10010;
const int mod = 1e9+7;
int dp[N][6][6];

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int distinctSequences(int n) {
        memset(dp, 0, sizeof(dp));
        if(n == 1) {
            return 6;
        }
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(gcd(i + 1, j + 1) == 1 && i != j) {
                    dp[2][i][j] = 1;
                }
            }
        }
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    if(j != k && gcd(j + 1, k + 1) == 1) {
                        for(int u =0; u < 6; u++) {
                            if(u != j && u != k && gcd(u + 1, j + 1) == 1) {
                                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][u][j]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                res = (res + dp[n][i][j]) % mod;
            }
        }
        return res;
    }
};