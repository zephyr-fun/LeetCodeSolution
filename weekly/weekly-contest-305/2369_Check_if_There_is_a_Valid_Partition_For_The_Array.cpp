// 2022.08.07 contest 2022.08.15 update
// class Solution {
// public:
//     bool res = false;
//     vector<int> nums;
//     int n;
//     void dfs(int cur) {
//         if(res == true) {
//             return ;
//         }
//         if(cur == n) {
//             res = true;
//         }
//         if(cur + 1 < n && nums[cur] == nums[cur + 1]) {
//             dfs(cur + 2);
//         }
//         if(cur + 2 < n && nums[cur] == nums[cur + 1] && nums[cur + 1] == nums[cur + 2]) {
//             dfs(cur + 3);
//         }
//         if(cur + 2 < n && nums[cur] == nums[cur + 1] - 1 && nums[cur + 1] == nums[cur + 2] - 1) {
//             dfs(cur + 3);
//         }
//     }
//     bool validPartition(vector<int>& nums_) {
//         nums = nums_;
//         n = nums.size();
//         dfs(0);
//         return res;
//     }
// };
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[1] = false;
        for(int i = 2; i <= n; i++) {
            if(dp[i - 2] && nums[i - 1] == nums[i - 2]) {
                dp[i] = true;
            }
            if(i >= 3 && dp[i - 3] && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) {
                dp[i] = true;
            }
            if(i >= 3 && dp[i - 3] && nums[i - 1] - 1 == nums[i - 2] && nums[i - 2] - 1 == nums[i - 3]) {
                dp[i] = true;
            }
        }
        return dp[n];
    }
};