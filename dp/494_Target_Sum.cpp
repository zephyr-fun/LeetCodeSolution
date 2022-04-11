// 2022.4.11
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(abs(target) > sum){
            return 0;
        }
        if((target + sum) % 2 == 1){
            return 0;
        }
        int bagWeight = (target + sum) / 2;
        vector<int> dp(bagWeight + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagWeight; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagWeight];
    }
};