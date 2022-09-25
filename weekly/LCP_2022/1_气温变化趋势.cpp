// 2022.09.24
class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        vector<int> ta;
        vector<int> tb;
        int n = temperatureA.size();
        for(int i = 1; i < n; i++) {
            ta.emplace_back(temperatureA[i] > temperatureA[i - 1] ? 1 : temperatureA[i] < temperatureA[i - 1] ? -1 : 0);
            tb.emplace_back(temperatureB[i] > temperatureB[i - 1] ? 1 : temperatureB[i] < temperatureB[i - 1] ? -1 : 0);
        }
        vector<int> dp(n, 0);
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            if(ta[i] == tb[i]) {
                dp[i + 1] = dp[i] + 1;
                res = max(res, dp[i + 1]);
            }
        }
        return res;
    }
};