// 2022.06.05
// recursion
class Solution {
public:
    int recursion(vector<int>& nums, bool mode) {
        if(nums.size() == 2) {
            if(mode) {
                return min(nums[0], nums[1]);
            }
            else {
                return max(nums[0], nums[1]);
            }
        }
        else {
            int size = nums.size();
            vector<int> left(nums.begin(), nums.begin() + size / 2);
            vector<int> right(nums.begin() + size / 2, nums.end());
            if(mode) {
                return min(recursion(left, true), recursion(right, false));
            }
            else {
                return max(recursion(left, true), recursion(right, false));
            }
        }
        return -1;
    }
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        return recursion(nums, true);
    }
};