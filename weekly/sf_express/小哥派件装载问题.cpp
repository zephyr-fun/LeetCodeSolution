// 2022.06.19
class Solution {
public:
    int minRemainingSpace(vector<int>& N, int V) {
        sort(N.begin(), N.end());
        vector<int> dp(V + 1, 0);
        for(int i = 0; i < N.size(); i++) {
            for(int j = V; j >= N[i]; j--) {
                dp[j] = max(dp[j], dp[j - N[i]] + N[i]);
            }
        }
        return V - dp[V];
    }
};