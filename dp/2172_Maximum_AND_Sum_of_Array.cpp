// 2022.09.09
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int res = 0;
        vector<int> dp(1 << (numSlots * 2));
        for(int i = 0; i < dp.size(); i++) {
            int c = __builtin_popcount(i);
            // alternative
            // int c = 0;
            // int temp = i;
            // while(temp) {
            //     temp = temp & (temp - 1);
            //     c++;
            // }
            if(c >= nums.size()) {
                continue;
            }
            for(int j = 0; j < numSlots * 2; j++) {
                if((i & (1 << j)) == 0) { // empty bucket
                    int s = i | (1 << j);
                    dp[s] = max(dp[s], dp[i] + ((j / 2 + 1) & nums[c]));
                    res = max(res, dp[s]);
                }
            }
        }
        return res;
    }
};