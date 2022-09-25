// 2022.09.25
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int res = 1;
        int n = nums.size();
        for(auto& num : nums) {
            maxVal = max(maxVal, num);
        }
        int left = 0;
        int right = 0;
        while(right < n) {
            while(right < n && nums[right] != maxVal) {
                left++;
                right++;
            }
            while(right < n && nums[right] == maxVal) {
                right++;
            }
            res = max(res, right - left);
            left = right;
        }
        return res;
    }
};