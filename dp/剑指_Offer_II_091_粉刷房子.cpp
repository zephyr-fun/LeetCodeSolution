// 2022.06.25
// dfs + cut TLE
class Solution {
public:
    int res = 0x3f3f3f3f;
    void dfs(vector<vector<int>>& costs, int cur, int prev, int sum) {
        if(sum >= res) {
            return ;
        }
        if(cur == costs.size()) {
            res = min(res, sum);
            return ;
        }
        for(int i = 0; i < 3; i++) {
            if(i == prev) {
                continue;
            }
            dfs(costs, cur + 1, i, sum + costs[cur][i]);
        }
    }
    int minCost(vector<vector<int>>& costs) {
        dfs(costs, 0, -1, 0);
        return res;
    }
};

// dp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        // dp[i][j] refers to the minimum cost considering first i house with the last paint in j color
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};

// 2022.08.08
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for(int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = min(dp[i - 1][(j - 1 + 3) % 3], dp[i - 1][(j + 1) % 3]) + costs[i][j];
            }
        }
        int res = 0x3f3f3f3f;
        for(int i = 0; i < 3; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};

// 2022.08.24
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0x3f3f3f3f));
        for(int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};