// 2022.08.22
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cur = 1;
        int res = 0;
        while(right < n) {
            cur = cur * nums[right];
            right++;
            while(left < right && cur >= k) {
                cur = cur / nums[left];
                left++;
            }
            res += right - left;
        }
        return res;
    }
};