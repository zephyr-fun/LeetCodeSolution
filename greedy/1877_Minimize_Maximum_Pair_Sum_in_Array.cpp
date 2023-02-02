// 2023.02.02
// double pointers
// greedy
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n - 1;
        while(left < right) {
            res = max(res, nums[left] + nums[right]);
            left++;
            right--;
        }
        return res;
    }
};