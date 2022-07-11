// 2022.07.11
// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = 0x3f3f3f3f;
        int res = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            minVal = min(minVal, prices[i]);
            res = max(res, prices[i] - minVal);
        }
        return res;
    }
};

// dp
// 0 means hold the stock
// 1 means already sold
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        int res = 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
            res = max(res, dp[i][1]);
        }
        return res;
    }
};

// monotonic stack
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.emplace_back(-1);
        int n = prices.size();
        vector<int> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.back() > prices[i]) {
                res = max(res, st.back() - st.front());
                st.pop_back();
            }
            st.emplace_back(prices[i]);
        }
        return res;
    }
};