// 2022.05.10
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) {
                dp[j] = 0; // dont understand
                for(int t = 1; t <= k; t++) {
                    if(j >= t) {
                        dp[j] = (dp[j] + dp[j - t]) % mod;
                    }
                }
            }
        }
        return dp[target];
    }
};

// 2022.05.11
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        // dp[j] refers to the posibility of consisting sum j
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // key point, you can only get sum 0 when you dice 0 time
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) { // j >= 0, when you start to dice, you can never get 0
                dp[j] = 0;
                for(int t = 1; t <= k; t++) {
                    if(j - t >= 0) {
                        dp[j] = (dp[j] + dp[j - t]) % mod;
                    }
                }
            }
            cout << "i = " << i;
            for(auto num : dp) {
                cout << num;
            }
            cout << endl;
        }
        return dp[target];
    }
};

// 2022.05.28
// 2 dim
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        // dp[i][j] refers to total plans of getting j sum with considering first i dice
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                for(int t = 1; t <= k; t++) {
                    if(j - t >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - t]) % mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};

// optim i dim
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        // dp[j] refers to total plans of getting j sum with considering first i dice
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = target; j >= 0; j--) {
                dp[j] = 0;
                for(int t = 1; t <= k; t++) {
                    if(j - t >= 0) {
                        dp[j] = (dp[j] + dp[j - t]) % mod;
                    }
                }
            }
        }
        return dp[target];
    }
};