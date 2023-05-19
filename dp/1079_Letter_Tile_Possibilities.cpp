// 2023.05.19
const int mx = 8;
int c[mx][mx];
int init = []() {
    for(int i = 0; i < mx; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return 0;
}();

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> map;
        for(auto& c : tiles) {
            map[c]++;
        }
        int n = tiles.size();
        int m = map.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int i = 1;
        for(auto& [_, cnt] : map) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= j && k <= cnt; k++) {
                    dp[i][j] += dp[i - 1][j - k] * c[j][k];
                }
            }
            i++;
        }
        return accumulate(dp[m] + 1, dp[m] + n + 1, 0);
    }
};

// dfs
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        return dfs(tiles, 0) - 1;
    }
    int dfs(string& tiles, int u) {
        int res = 1;
        if(u == tiles.size()) {
            return res;
        }
        for(int i = 0; i < tiles.size(); i++) {
            if(i && tiles[i] == tiles[i - 1]) {
                continue;
            }
            if(tiles[i] == ' ') {
                continue;
            }
            char temp = tiles[i];
            tiles[i] = ' ';
            res += dfs(tiles, u + 1);
            tiles[i] = temp;
        }
        return res;
    }
};