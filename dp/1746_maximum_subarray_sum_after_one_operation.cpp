// 2022.09.03
class Solution {
public:
    int maxSumAfterOperation(vector<int> nums) {
        int dp1 = 0;
        int dp2 = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            dp1 = max(dp1 + nums[i], dp2 + nums[i] * nums[i]);
            dp2 = max(dp2 + nums[i], 0);
            res = max(res, dp1);
        }
        return res;
    }
}