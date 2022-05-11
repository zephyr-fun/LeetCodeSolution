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