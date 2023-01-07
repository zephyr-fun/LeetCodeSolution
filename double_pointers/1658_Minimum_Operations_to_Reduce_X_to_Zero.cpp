// 2023.01.07
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) {
            return -1;
        }
        int left = 0;
        int sum = 0;
        int n = nums.size();
        int res = -1;
        for(int right = 0; right < n; right++) {
            sum += nums[right];
            while(sum > target) {
                sum -= nums[left];
                left++;
            }
            if(sum == target) {
                res = max(res, right - left + 1);
            }
        }
        return res < 0 ? -1 : n - res;
    }
};