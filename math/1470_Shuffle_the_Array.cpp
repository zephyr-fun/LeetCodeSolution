// 2022.08.29
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < 2 * n; i++) {
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & ((1 << 10) - 1)) << 10;
        }
        for(auto& num : nums) {
            num = num >> 10;
        }
        return nums;
    }
};