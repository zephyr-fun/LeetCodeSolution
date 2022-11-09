// 2022.11.09
const int N = 507;
int dp[N][N];
bool g[N][N];
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        memset(g, 1, sizeof(g));
        for(auto& mine : mines) {
            g[mine[0]][mine[1]] = false;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0, s = 0; j < N; j++) {
                if(g[i][j]) {
                    s++;
                }
                else {
                    s = 0;
                }
                dp[i][j] = s;
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = N - 1, s = 0; j >= 0; j--) {
                if(g[i][j]) {
                    s++;
                }
                else {
                    s = 0;
                }
                dp[i][j] = min(dp[i][j], s);
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0, s = 0; j < N; j++) {
                if(g[j][i]) {
                    s++;
                }
                else {
                    s = 0;
                }
                dp[j][i] = min(dp[j][i], s);
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = N - 1, s = 0; j >= 0; j--) {
                if(g[j][i]) {
                    s++;
                }
                else {
                    s = 0;
                }
                dp[j][i] = min(dp[j][i], s);
            }
        }
        int res = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};