// 2022.04.11
// order matters
// under the situation of complete bag
// objects first, bagweight second: combination
// bagweight first, objects second: arrange
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

// 2022.05.05
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j] refers to the total number of plans to consisting amount j
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

// 2022.05.13
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j] refers to number of ways to consist amount j
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};

// 2022.07.21
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // int mod = 1e9 + 7;
        for(auto coin : coins) {
            for(int j = coin; j <= amount; j++) {
                dp[j] = (dp[j] + dp[j - coin]);
            }
        }
        return dp[amount];
    }
};