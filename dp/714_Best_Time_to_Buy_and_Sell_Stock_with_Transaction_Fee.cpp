// 2022.04.07
// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            if(prices[i] > minPrice + fee){
                res += prices[i] - minPrice - fee; // -fee
                minPrice = prices[i] - fee; // -fee
            }
        }
        return res;
    }
};

// dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // status 0: take
        // status 1: not take
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};