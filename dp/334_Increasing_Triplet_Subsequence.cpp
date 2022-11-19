// 2022.11.19
// LIS
// optim
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int dp[2];
        dp[0] = INT_MAX;
        dp[1] = INT_MAX;
        for(auto num : nums) {
            if(num > dp[1]) {
                return true;
            }
            else if(num > dp[0] && num < dp[1]) {
                dp[1] = num;
            }
            else if(num < dp[0]) {
                dp[0] = num;
            }
        }
        return false;
    }
};