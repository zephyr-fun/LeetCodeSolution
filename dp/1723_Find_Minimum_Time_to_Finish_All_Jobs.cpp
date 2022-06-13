// 2022.06.13
// dp
// https://leetcode.cn/problems/find-minimum-time-to-finish-all-jobs/solution/zhuang-ya-dp-jing-dian-tao-lu-xin-shou-j-3w7r/
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n, 0);
        for(int i = 1; i < (1 << n); i++) {
            for(int j = 0; j < n; j++) {
                if((i & (1 << j)) == 0) { // note the priority of & opt
                    continue;
                }
                int left = i - (1 << j);
                tot[i] = tot[left] + jobs[j];
                break;
            }
        }
        vector<vector<int>> dp(k, vector<int>(1 << n, -1));
        for(int i = 0; i < (1 << n); i++) {
            dp[0][i] = tot[i];
        }
        for(int i = 1; i < k; i++) {
            for(int j = 0; j < (1 << n); j++) {
                int minVal = 0x3f3f3f3f;
                for(int s = j; s; s = (s - 1) & j) {
                    int left = j - s;
                    int val = max(dp[i - 1][left], tot[s]);
                    minVal = min(minVal, val);
                }
                dp[i][j] = minVal;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};