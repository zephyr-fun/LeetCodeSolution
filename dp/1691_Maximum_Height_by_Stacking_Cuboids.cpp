// 2022.12.10
// https://leetcode.cn/problems/maximum-height-by-stacking-cuboids/solution/tu-jie-suan-fa-you-hua-xiang-xi-zheng-mi-b6fq/
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        int dp[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 0;
            for(int j = 0; j < i; j++) {
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j]); // put j on i
                }
            }
            dp[i] += cuboids[i][2];
        }
        return *max_element(dp, dp + n);
    }
};