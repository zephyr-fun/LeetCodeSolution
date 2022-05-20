// 2022.05.12
// plain dp
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // consider job as item, profit as value, group as weight
        // dp[i][j][k] refers to the total plan number of considering first i job, with at most j people, totalValue at least (greater or equal to) k
        int mod = 1e9 + 7;
        int jobNum = group.size();
        int peopleNum = n;
        vector<vector<vector<long>>> dp(jobNum + 1, vector<vector<long>>(peopleNum + 1, vector<long>(minProfit + 1, 0)));
        for(int j = 0; j <= peopleNum; j++) {
            dp[0][j][0] = 1;
        }
        for(int i = 1; i <= jobNum; i++) {
            int curNeedPeople = group[i - 1];
            int curProfit = profit[i - 1];
            for(int j = 0; j <= peopleNum; j++) {
                for(int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(j >= curNeedPeople) {
                        dp[i][j][k] += dp[i - 1][j - curNeedPeople][max(0, k - curProfit)];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }
        // for(int i = 0; i <= jobNum; i++) {
        //     for(int j = 0; j <= peopleNum; j++) {
        //         for(int k = 0; k <= minProfit; k++) {
        //             cout << dp[i][j][k];
        //         }
        //         cout << endl;
        //     }
        //     cout << "****" << endl;
        // }
        return dp[jobNum][peopleNum][minProfit];
    }
};

// optim i dim
class Solution {
    int mod = 1e9 + 7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int itemNum = group.size();
        int peopleNum = n;
        // dp[j][k] refers to the total number plans of using as most j people to get at least k profit
        vector<vector<long>> dp(peopleNum + 1, vector<long>(minProfit + 1, 0));
        for(int j = 0; j <= peopleNum; j++) {
            dp[j][0] = 1;
        }
        for(int i = 1; i <= itemNum; i++) {
            int curNeed = group[i - 1];
            int curProfit = profit[i - 1];
            for(int j = peopleNum; j >= curNeed; j--) {
                for(int k = minProfit; k >= 0; k--) {
                    dp[j][k] += dp[j - curNeed][max(k - curProfit, 0)];
                    dp[j][k] %= mod;
                }
            }
        }
        return dp[peopleNum][minProfit];
    }

};

// 2022.05.20
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        // dp[i][j][k] refers to the total plan, considering the frist i work, with j people,  at least k profit
        int numWork = profit.size();
        vector<vector<vector<int>>> dp(numWork + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        for(int j = 0; j <= n; j++) {
            dp[0][j][0] = 1;
        }    
        for(int i = 1; i <= numWork; i++) {
            int curNeed = group[i - 1];
            int curProfit = profit[i - 1];
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(j >= curNeed) {
                        dp[i][j][k] += dp[i - 1][j - curNeed][max(0, k - curProfit)];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }
        return dp[numWork][n][minProfit];
    }
};

// optim i dim
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        int numWork = profit.size();
        // dp[j][k] refers to total plans of considering first i work, with j people, at least k profit
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for(int j = 0; j <= n; j++) {
            dp[j][0] = 1; // with first 0 work
        }
        for(int i = 1; i <= numWork; i++) {
            int curNeed = group[i - 1];
            int curProfit = profit[i - 1];
            for(int j = n; j >= 0; j--) {
                for(int k = minProfit; k >= 0; k--) {
                    if(j >= curNeed) {
                        dp[j][k] += dp[j - curNeed][max(0, k - curProfit)];
                        dp[j][k] %= mod;
                    }
                }
            }
        }
        return dp[n][minProfit];
    }
};