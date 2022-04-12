// 2022.04.12
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        // init
        for(int i = 1; i < 2 * k; i += 2){
            dp[0][i] = -prices[0];
        }
        // dp
        for(int i = 1; i < prices.size(); i++){
            for(int j = 0; j < 2 * k - 1; j += 2){
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};