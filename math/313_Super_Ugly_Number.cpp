// 2022.09.29
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int pn = primes.size();
        vector<int> po(pn, 1);
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int temp = INT_MAX;
            vector<int> plus;
            for(int j = 0; j < pn; j++) {
                if((long long)primes[j] * (long long)dp[po[j]] < temp) {
                    temp = primes[j] * dp[po[j]];
                    plus.clear();
                    plus.emplace_back(j);
                }
                else if((long long)primes[j] * (long long)dp[po[j]] == temp) {
                    plus.emplace_back(j);
                }
            }
            dp[i] = temp;
            for(auto& p : plus) {
                po[p]++;
            }
        }
        return dp[n];
    }
};