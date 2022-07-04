// 2022.07.04
// dfs
class Solution {
public:
    unordered_map<int, vector<int>> map;
    int n;
    int k;
    int m;
    int res = 0;
    int numWays(int n_, vector<vector<int>>& relation, int k_) {
        k = k_;
        n = n_;
        m = relation.size();
        for(int i = 0; i < m; i++) {
            map[relation[i][0]].emplace_back(relation[i][1]);
        }
        dfs(0, 0);
        return res;
    }
    void dfs(int cur, int step) {
        if(step == k) {
            if(cur == n - 1) {
                res += 1;
            }
            return ;
        }
        int size = map[cur].size();
        for(int i = 0; i < size; i++) {
            dfs(map[cur][i], step + 1);
        }
    }
};

// dp
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        // dp[i][j] refers to total num of after i step located in j
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= k; i++) {
            for(auto rs : relation) {
                int start = rs[0];
                int end = rs[1];
                dp[i][end] += dp[i - 1][start];
            }
        }
        return dp[k][n - 1];
    }
};