// 2022.09.12
class Solution {
public:
    int check(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int pos = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos == -1 ? nums.size() : nums.size() - 1 - pos;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size();
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(check(nums, mid) > mid) {
                left = mid + 1;
            }
            else if(check(nums, mid) < mid) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};