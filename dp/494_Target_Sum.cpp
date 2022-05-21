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

// 2022.05.09
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(abs(target) > sum) {
            return 0;
        }
        if((target + sum) % 2 == 1) {
            return 0;
        }
        // find two sets of nums
        // set a with '+'
        // set b with '-'
        // a + b = sum, a - b = target
        // a = (target + sum) / 2
        int aTarget = (target + sum) / 2;
        // dp[j] refers to the ways to fill j bagWeight
        vector<int> dp(aTarget + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = aTarget; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[aTarget];
    }
};

// 2022.05.21
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // set a, b
        // a + b = sum(nums)
        // a - b = target
        // a = (sum + target) / 2
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if(abs(target) > sum) {
            return 0;
        }
        if((sum + target) % 2 != 0) {
            return 0;
        }
        int val = (sum + target) / 2;
        // dp[i][j] refers to considering first i nums, get sum = j, total nums
        vector<vector<int>> dp(nums.size() + 1, vector<int>(val + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 0; j <= val; j++) {
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][val];
    }
};

// optim i dim
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // set a, b
        // a + b = sum(nums)
        // a - b = target
        // a = (sum + target) / 2
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if(abs(target) > sum) {
            return 0;
        }
        if((sum + target) % 2 != 0) {
            return 0;
        }
        int val = (sum + target) / 2;
        // dp[j] refers to considering first i nums, get sum = j, total nums
        vector<int> dp(val + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = val; j >= 0; j--) {
                if(j >= nums[i - 1]) {
                    dp[j] += dp[j - nums[i - 1]];
                }
            }
        }
        return dp[val];
    }
};