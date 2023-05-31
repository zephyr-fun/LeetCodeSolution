// 2023.05.31
// memorable search
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int g[n][n];
        int f[n][n];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++) {
            g[i][i] = arr[i];
            for(int j = i + 1; j < n; j++) {
                g[i][j] = max(g[i][j - 1], arr[j]);
            }
        }
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(i == j) {
                return 0;
            }
            if(f[i][j]) {
                return f[i][j];
            }
            int res = 1 << 30;
            for(int k = i; k < j; k++) {
                res = min(res, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
            }
            f[i][j] = res;
            return res;
        };
        return dfs(0, n - 1);
    }
};

// dp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int g[n][n];
        int f[n][n];
        memset(f, 0, sizeof(f));
        for(int i = n - 1; i >= 0; i--) { // mind the order
            g[i][i] = arr[i];
            for(int j = i + 1; j < n; j++) {
                g[i][j] = max(g[i][j - 1], arr[j]);
                f[i][j] = 1 << 30;
                for(int k = i; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};