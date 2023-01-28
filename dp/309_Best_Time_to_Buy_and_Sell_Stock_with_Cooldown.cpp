// 2022.04.13
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][3], max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};

// 0：持有股票后的最多现金
// 1：不持有股票（能购买）的最多现金
// 2：不持有股票（冷冻期）的最多现金
// 3 states
// dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
// dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
// dp[i][2] = dp[i - 1][0] + prices[i];

// 2023.01.28
// 状态机
// 0：冷冻期（包括平常期）
// 1：持有期（持有状态）
// 2：今日卖出
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(3, -0x3f3f3f3f));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};