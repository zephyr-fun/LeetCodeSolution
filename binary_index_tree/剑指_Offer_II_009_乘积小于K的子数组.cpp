// 2022.08.30
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int left = 0;
        int right = 0;
        int cur = 1;
        while(right < n) {
            cur *= nums[right];
            right++;
            while(left < right && cur >= k) {
                cur /= nums[left];
                left++;
            }
            res += right - left;
        }
        return res;
    }
};