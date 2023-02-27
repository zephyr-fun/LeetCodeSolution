// 2023.02.27
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int left = 0x3f3f3f3f;
            int right = 0x3f3f3f3f;
            if(i - 1 >= 0) {
                left = min(left, nums[i - 1]);
            }
            if(i + 1 < n) {
                right = min(right, nums[i + 1]);
            }
            if(nums[i] >= min(left, right)) {
                if(i & 1) {
                    sum1 += nums[i] - min(left, right) + 1;
                }
                else {
                    sum2 += nums[i] - min(left, right) + 1;
                }
            }
        }
        return min(sum1, sum2);
    }
};