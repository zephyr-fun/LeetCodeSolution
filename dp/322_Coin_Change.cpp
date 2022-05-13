// 2022.04.11
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1); // INT_MAX - 1 avoid overflow
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX - 1){
            return -1;
        }
        return dp[amount];
    }
};

// 2022.05.04
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] refers to the minimum of coins to consisting amount i
        vector<int> dp(amount + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i] >= 0) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};

// 2022.05.13
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[j] refers to the minimum number of coins to consisting amount j
        vector<int> dp(amount + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(j >= coins[i]) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};