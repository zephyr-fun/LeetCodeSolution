// 2023.06.05
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int write = 0, scan = 0;
        while (scan < nums.size()) {
            if(scan+1 < nums.size() && nums[scan] == nums[scan+1] && nums[scan] != 0) {
                nums[write++] = nums[scan] * 2;
                scan += 2;
            } 
            else if(nums[scan] != 0) {
                nums[write++] = nums[scan++];
            } 
            else {
                scan++;
            }
        }
        while (write < nums.size()) {
            nums[write++] = 0;
        }
        return nums;
    }
};