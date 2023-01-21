// 2023.01.21
class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<int> dp = {1, 0, 1};
        for(int i = 1; i <= n; i++) {
            int minCur = inf;
            for(int j = 0; j < 3; j++) {
                if(j == obstacles[i] - 1) {
                    dp[j] = inf;
                }
                else {
                    minCur = min(minCur, dp[j]);
                }
            }
            for(int j = 0; j < 3; j++) {
                if(j == obstacles[i] - 1) {
                    continue;
                }
                else {
                    dp[j] = min(dp[j], minCur + 1);
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};

// https://leetcode.cn/problems/minimum-sideway-jumps/solution/cong-0-dao-1-de-0-1-bfspythonjavacgo-by-1m8z4/