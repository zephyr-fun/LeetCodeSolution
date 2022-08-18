// 2022.04.06
class Solution {
public:
    // price[3] - preice[0] = (preice[3] - preice[2]) + (preice[2] - preice[1]) + (preice[1] - preice[0])
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] - prices[i] > 0){
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};

// 2022.04.12
class Solution {
public:
    // price[3] - preice[0] = (preice[3] - preice[2]) + (preice[2] - preice[1]) + (preice[1] - preice[0])
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};

// 2022.08.17
// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        for(int i = 1; i < len; i++) {
            if(prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len - 1][0];
    }
};

// 2022.08.18
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[i][0] not hold stock, max interest
        // dp[i][0] hold stock, max interest
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};