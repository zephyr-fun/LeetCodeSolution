// 2023.03.27
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        int n = s.size();
        int m = t.size();
        int f[n + 1][m + 1];
        int g[n + 1][m + 1];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(s[i] == t[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
                else {
                    res += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return res;
    }
};