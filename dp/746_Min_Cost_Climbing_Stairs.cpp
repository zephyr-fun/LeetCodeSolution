// 2022.04.09
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1){
            return cost[0];
        }
        if(cost.size() == 2){
            return min(cost[0], cost[1]);
        }
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

// optim space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1){
            return cost[0];
        }
        if(cost.size() == 2){
            return min(cost[0], cost[1]);
        }
        int dp[2];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int sum = min(dp[1], dp[0]) + cost[i];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return min(dp[0], dp[1]);
    }
};

// 2022.05.03
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        if(cost.size() == 2) {
            return min(dp[0], dp[1]);
        }
        for(int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

// optim space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(2, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        if(cost.size() == 2) {
            return min(dp[0], dp[1]);
        }
        for(int i = 2; i < cost.size(); i++) {
            dp[0] = min(dp[0], dp[1]) + cost[i];
            dp[0] ^= dp[1];
            dp[1] ^= dp[0];
            dp[0] ^= dp[1];
        }
        return min(dp[0], dp[1]);
    }
};

// 2022.08.07
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[n - 2], dp[n - 1]);
    }
};