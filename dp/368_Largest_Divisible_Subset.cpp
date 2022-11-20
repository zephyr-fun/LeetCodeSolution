// 2022.11.20
// https://leetcode.cn/problems/largest-divisible-subset/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-0a3jc/
// like LIS
// a <= b
// b % a == 0
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> g(n, 0);
        for(int i = 0; i < n; i++) {
            int len = 1;
            int prev = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > len) {
                        len = dp[j] + 1;
                        prev = j;
                    }
                }
            }
            dp[i] = len;
            g[i] = prev;
        }
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        int maxVal = dp[idx];
        vector<int> res;
        while(res.size() != maxVal) {
            res.emplace_back(nums[idx]);
            idx = g[idx];
        }
        return res;
    }
};