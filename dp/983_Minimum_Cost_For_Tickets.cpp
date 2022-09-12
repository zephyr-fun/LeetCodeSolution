// 2022.09.12
// memo
class Solution {
public:
    unordered_set<int> dayset;
    vector<int> costs;
    int dp[366] = {0};
    int dfs(int cur) {
        if(cur > 365) {
            return 0;
        }
        if(dp[cur] != -1) {
            return dp[cur];
        }
        if(dayset.count(cur)) {
            dp[cur] = min(dfs(cur + 1) + costs[0], min(dfs(cur + 7) + costs[1], dfs(cur + 30) + costs[2]));
        }
        else {
            dp[cur] = dfs(cur + 1);
        }
        return dp[cur];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs_) {
        costs = costs_;
        for(auto day : days) {
            dayset.insert(day);
        }
        memset(dp, -1, sizeof(dp));
        return dfs(1);
    }
};

// dp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> set;
        vector<int> dp(days[n - 1] + 31, 0);
        for(auto day : days) {
            set.insert(day);
        }
        for(int i = days[n - 1]; i >= days[0]; i--) {
            if(set.count(i)) {
                dp[i] = min(dp[i + 1] + costs[0], min(dp[i + 7] + costs[1], dp[i + 30] + costs[2]));
            }
            else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[days[0]];
    }
};