// 2022.05.05
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0;
        int timeRes = 1;
        int res = 0;
        if(k <= 1) {
            return 0;
        }
        while(left <= right && right < nums.size()) {
            timeRes *= nums[right];
            while(timeRes >= k) {
                timeRes /= nums[left];
                left++;
            }
            res += right - left + 1; // reason as below, means the sub array ends with nums[right]
            right++;
        }
        return res;
    }
};
// timeRes    left    right    res          join
//    10        0       0       1           (10)
//    50        0       1       3        (10, 5) (5)
// 100->10      1       2       5        (5, 2) (2)
//    60        1       3       8     (5, 2, 6) (2, 6) (6)