// 2022.11.23
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int pos = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid + 1;
                pos = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return pos >= n - 1 ? nums[0] : nums[pos + 1];
    }
};